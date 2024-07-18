# [383. Ransom Note](https://leetcode.com/problems/ransom-note/)

## Description

Given two strings `ransomNote` and `magazine`, return _`true` if `ransomNote` can be constructed by using the letters from `magazine` and `false` otherwise_.

Each letter in `magazine` can only be used once in `ransomNote`.


**Example 1:**
```go
Input: ransomNote = "a", magazine = "b"
Output: false
```

**Example 2:**

```go
Input: ransomNote = "aa", magazine = "ab"
Output: false
```

**Example 3:**
```go
Input: ransomNote = "aa", magazine = "aab"
Output: true
```

**Constraints:**
* `1 <= ransomNote.length, magazine.length <= 10^5`
* `ransomNote` and `magazine` consist of lowercase English letters.