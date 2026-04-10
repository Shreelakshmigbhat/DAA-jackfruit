# N-Queens Secure Vault Placement

DAA Jackfruit — Question 3  
Technique: Backtracking with O(1) conflict detection

## Build & Run

```bash
make
./nqueens
```

## Files

| File | Purpose |
|---|---|
| `include/nqueens.h` | All type definitions and function declarations |
| `src/nqueens.c` | Core algorithm: `board_init`, `is_safe`, `backtrack`, `solve`, `count_solutions` |
| `src/utils.c` | Board printing utilities |
| `src/main.c` | Driver: test cases 1–5 |

## Complexity

| Operation | Time | Space |
|---|---|---|
| `is_safe()` | O(1) | — |
| `solve()` worst case | O(N!) | O(N) |
| `count_solutions()` | O(N!) | O(N) |

## Expected Output (selected)

```
4-Queens: 2 solutions
8-Queens: 92 solutions
10-Queens: 724 solutions
```
