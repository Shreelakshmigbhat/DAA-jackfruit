# Treap Implementation in C

## Overview
This project implements a **Treap**, a randomized binary search tree that combines:
- Binary Search Tree (BST) property on keys
- Heap property on randomly assigned priorities

This ensures expected balanced height and efficient operations.

---

## Features
- Insert operation
- Delete operation
- Search operation
- Inorder traversal (sorted output)

---

## How It Works

Each node contains:
- `key` → used for BST ordering
- `priority` → random value for heap ordering

During insertion:
- Node is inserted like a BST
- Rotations are used to maintain heap property

---

## Time Complexity

| Operation | Expected Time |
|----------|-------------|
| Insert   | O(log n)    |
| Delete   | O(log n)    |
| Search   | O(log n)    |

---

## Compilation

```bash
gcc main.c treap.c -o treap
./treap
