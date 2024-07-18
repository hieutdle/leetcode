# [1512. Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)

## Description

Given an array of integers `nums`, return the _number of **good pairs**_.

A pair `(i,j)` is called _good_ if `nums[i] == nums[j]` and `i < j`.



**Example 1**:

```go
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
```

**Example 2**:

```go
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
```

**Example 3**:

```go
Input: nums = [1,2,3]
Output: 0
```

**Constraints**:

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 100`