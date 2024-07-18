# [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)


## Description

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level). 

**Example 1:**

![](../../../figures/tree102.jpg)

```go
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**Example 2:**

```go
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```go
Input: root = []
Output: []
```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 2000]`.
* `-1000 <= Node.val <= 1000`