#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int adj[MAXN][100];
int deg[MAXN];
int values[MAXN];
int isPrime[MAXN];

int start[MAXN], endt[MAXN];
int euler[MAXN];
int prefix[MAXN + 1];

// Sieve
void sieve(int max_val) {
    for (int i = 0; i <= max_val; i++)
        isPrime[i] = 1;

    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= max_val; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= max_val; j += i)
                isPrime[j] = 0;
        }
    }
}

// Euler Tour (Iterative DFS)
void eulerTour(int n) {
    int stack[MAXN][3];
    int top = -1;
    int time = 0;

    stack[++top][0] = 0;
    stack[top][1] = -1;
    stack[top][2] = 0;

    while (top >= 0) {
        int node = stack[top][0];
        int parent = stack[top][1];
        int state = stack[top][2];
        top--;

        if (state == 0) {
            start[node] = time;
            euler[time++] = node;

            stack[++top][0] = node;
            stack[top][1] = parent;
            stack[top][2] = 1;

            for (int i = deg[node] - 1; i >= 0; i--) {
                int nei = adj[node][i];
                if (nei != parent) {
                    stack[++top][0] = nei;
                    stack[top][1] = node;
                    stack[top][2] = 0;
                }
            }
        } else {
            endt[node] = time - 1;
        }
    }
}

// Main logic
void efficiencyScores(int n, int edges[][2], int values_input[],
                      int queries[], int q) {

    for (int i = 0; i < n; i++) {
        values[i] = values_input[i];
        deg[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    int max_val = 0;
    for (int i = 0; i < n; i++)
        if (values[i] > max_val)
            max_val = values[i];

    sieve(max_val);
    eulerTour(n);

    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        int node = euler[i];
        prefix[i + 1] = prefix[i] + (isPrime[values[node]] ? 1 : 0);
    }

    printf("\nResults:\n");
    for (int i = 0; i < q; i++) {
        int node = queries[i];
        int ans = prefix[endt[node] + 1] - prefix[start[node]];
        printf("Query node %d -> Prime count = %d\n", node, ans);
    }
}

// MAIN FUNCTION
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int edges[n - 1][2];
    printf("Enter %d edges (u v):\n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int values_input[n];
    printf("Enter values of %d nodes:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &values_input[i]);
    }

    int q;
    printf("Enter number of queries: ");
    scanf("%d", &q);

    int queries[q];
    printf("Enter %d query nodes:\n", q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &queries[i]);
    }

    efficiencyScores(n, edges, values_input, queries, q);

    return 0;
}