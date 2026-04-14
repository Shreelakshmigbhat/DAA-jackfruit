# **DAA Jackfruit – Set 88 (Question 2)**

## **Randomized Algorithms and Treaps**

---

## **Introduction**

Randomization is a powerful technique used in algorithms to avoid worst-case scenarios. Randomised Quicksort uses random pivot selection to achieve expected (O(n \log n)) performance. Similarly, Treaps combine Binary Search Trees and Heap properties using random priorities to maintain balanced trees in expectation.

---

# **Task 1: Randomised Quicksort Analysis**


Randomised Quicksort selects a pivot uniformly at random.

Let `X[i][j]` be an indicator variable:

* `X[i][j] = 1` if elements `i` and `j` are compared
* `X[i][j] = 0` otherwise

---

### **Total Comparisons**

```
X = sum over all i < j of X[i][j]
```

---

### **Using Linearity of Expectation**

```
E[X] = sum over all i < j of E[X[i][j]]
```

---

### **Probability of Comparison**

```
P(X[i][j] = 1) = 2 / (j - i + 1)
```

---

### **Final Result**

```
E[X] = sum over all i < j of (2 / (j - i + 1)) = O(n log n)
```

---

### **Conclusion**

Random pivot selection ensures that the expected number of comparisons in Quicksort is `O(n log n)`, avoiding worst-case behavior.


---

# **Task 2: Deterministic Quicksort Worst Case**

In deterministic Quicksort, pivot selection is fixed.

An adversary can construct inputs such that:

* Each partition is maximally unbalanced

Recurrence:
[
T(n) = T(n-1) + O(n)
]

[
T(n) = O(n^2)
]

**Conclusion:**
No deterministic comparison-based sorting algorithm can avoid (O(n^2)) worst-case under adversarial inputs.

---

# **Task 3: Treap Definition and Height Analysis**

## **Definition**

A Treap is a binary tree that satisfies:

* **BST Property:** Left < Root < Right
* **Heap Property:** Parent priority < child priority

Each node has:

* Key (for BST)
* Random priority (for heap)

---

## **Height Analysis**

Treap behaves like a BST built with random insertion order.

From random BST theory:
[
\text{Expected height} = O(\log n)
]

**Conclusion:**
Random priorities ensure expected logarithmic height.

---

# **Task 4: Treap Implementation**

## **Features**

* Insert operation
* Delete operation
* Search operation
* Inorder traversal

## **Code Files**

* `treap.c`
* `treap.h`
* `main.c`

## **How to Compile**

```bash
gcc main.c treap.c -o treap
./treap
```

---

## **Sample Input**

```
Enter the number of elements to insert: 5
Enter keys:
10 20 30 40 50
Enter a key to search: 30
Enter a key to delete: 20
```

---

## **Sample Output**

```
Inorder traversal: 10 20 30 40 50
Search 30: Found
After deleting 20: 10 30 40 50
```

---

## **Explanation**

* Inorder traversal confirms BST property (sorted order)
* Search verifies correctness
* Delete operation maintains structure using rotations
* Random priorities ensure balanced tree structure

---

# **Task 5: Time Complexity**

| Operation | Expected Time |
| --------- | ------------- |
| Insert    | O(log n)      |
| Delete    | O(log n)      |
| Search    | O(log n)      |

**Explanation:**
Since the height of the Treap is (O(\log n)) in expectation, all operations take logarithmic time.

---

# **Task 6: Comparison with AVL and Red-Black Trees**

| Feature    | Treap             | AVL                 | Red-Black           |
| ---------- | ----------------- | ------------------- | ------------------- |
| Balance    | Random            | Strict              | Moderate            |
| Height     | Expected O(log n) | Guaranteed O(log n) | Guaranteed O(log n) |
| Complexity | Simple            | Complex             | Moderate            |

---

## **Discussion**

* AVL trees provide strict balance but require more rotations
* Red-Black trees provide moderate balance with fewer rotations
* Treaps are simpler and rely on randomness for balancing

**Conclusion:**
Treaps are preferred when simplicity and expected performance are sufficient, while AVL and Red-Black trees are used when strict worst-case guarantees are required.

---

# **Final Conclusion**

Randomisation helps eliminate worst-case behavior in algorithms. Randomised Quicksort achieves expected (O(n \log n)) time, while Treaps maintain expected logarithmic height through random priorities. This demonstrates how randomness can simplify design while maintaining efficiency.

---
