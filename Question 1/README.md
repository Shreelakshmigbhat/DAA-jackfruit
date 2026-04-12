# Problem Statement

Uber's city infrastructure team is analyzing a network of service hubs across a metropolitan area.

- The hubs are connected in a **tree structure**
(connected graph, no cycles)
- Each hub has an **efficiency score (integer)**
- You are given multiple **queries**

---

## For each query:

Given a node (hub), you must:

> Count how many nodes in its subtree (including itself) have **prime efficiency scores**

### 


# **Task 1: Design Efficient Algorithm**

To efficiently answer multiple subtree queries, we use the Euler Tour Technique combined with Prefix Sums.

1. Precompute prime numbers up to the maximum efficiency score using the Sieve of Eratosthenes.
2. Represent the tree using an adjacency list.
3. Perform an Euler Tour (DFS traversal) of the tree:
    - Record entry time (start[node])
    - Record exit time (end[node])
    - Store nodes in an Euler array
4. Key Insight:
    - The subtree of any node forms a contiguous segment in the Euler array.
5. Build a prefix sum array:
    - prefix[i] = number of prime-valued nodes from index 0 to i-1 in the Euler array
6. For each query node q:
    - Answer = prefix[end[q] + 1] - prefix[start[q]]

This ensures each query is answered in O(1) time after preprocessing.

## **Simpler :**

Algorithm: SubtreePrimeCount

Input: Tree with n nodes, scores[], queries[]
Output: Prime count for each query node

Preprocessing:

1. isPrime[] ← Sieve(max(scores))
2. Perform DFS from root:
    - start[u] = entry time
    - end[u] = exit time
    - euler[] = nodes in DFS order
3. Build prefix[] where prefix[i] = prime count in euler[0..i-1]

Query Answer for node q:
return prefix[end[q]+1] - prefix[start[q]]

##

## Task 3: Prime Checking Method

We use the Sieve of Eratosthenes to efficiently compute prime numbers.

- Time Complexity: O(M log( log M)), where M is the maximum efficiency score.
- 0 and 1 are marked as non-prime.
- If max_val < 2, all numbers are non-prime.
- Efficiency scores are assumed to be non-negative integers.

##

## Task 4: Time Complexity Analysis

Let:
N = number of nodes (≤ 10^5)
M = maximum efficiency score (≤ 10^5)
Q = number of queries (≤ 10^5)

- Prime preprocessing: O(M log( log M))
- Euler Tour traversal: O(N)
- Prefix sum computation: O(N)
- Each query: O(1)

Total Time Complexity: O(N + M·log(log M) + Q)

Space Complexity: O(N + M)
After preprocessing, each prime check is performed in O(1) time using isPrime[] array.




##

## Task 5: Performance and Optimization

### Static Tree
- Efficient for large inputs up to 10^5 nodes and queries
- Preprocessing done once, queries answered in O(1)

### Online Queries
- Since each query is O(1), it works efficiently even if queries come one-by-one

### Dynamic Updates (Node values change)
- Use Fenwick Tree (Binary Indexed Tree) on Euler Tour
- Update: O(log N), Query: O(log N)

### Structural Changes (Tree updates)
- Use Euler Tour Tree (ETT) or Link-Cut Tree
- Each operation: O(log N)
