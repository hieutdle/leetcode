# [976. Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/)

## Description

Given an integer array `nums`, return _the largest perimeter of a triangle with **non-zero** area, formed from three of these lengths_.
If it is impossible to form any triangle of **non-zero** area, return `0`.


**Example 1**:

```go
Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
```

**Example 2**:

```go
Input: nums = [1,2,1,10]
Output: 0
Explanation: 
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
```

**Constraints**:
* `3 <= nums.length <= 10^4`
* `1 <= nums[i] <= 10^6`