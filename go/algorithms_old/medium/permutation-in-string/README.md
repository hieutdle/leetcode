# [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)


## Description

Given two strings `s1` and `s2`, _return `true` if `s2` contains a permutation of `s1`, or `false` otherwise_.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.


**Example 1:**

```go
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
```

**Example 2:**

```go
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

**Constraints:**
* `1 <= s1.length, s2.length <= 10^4`
* `s1` and `s2` consist of lowercase English letters.
