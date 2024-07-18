# [290. Word Pattern](https://leetcode.com/problems/word-pattern/)

## Description 

Given a `pattern` and a string `s`, find if `s` follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** word in s.

**Example 1:**
```go
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
```

**Example 2:**
```go
Input: pattern = "abba", s = "dog cat cat fish"
Output: false
```

**Example 3:**
```go
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
```

**Example 4:**
```go
Input: pattern = "abba", s = "dog dog dog dog"
Output: false
```

**Example 5:**
```go
Input: pattern = "aaa", s= "aa aa aa aa"
Output: false
```

**Constraints:**
* `1 <= pattern.length <= 300`
* `pattern` contains only lower-case English letters.
* `1 <= s.length <= 3000`
* `s` contains only lowercase English letters and spaces `' '`.
* `s` **does not contain** any leading or trailing spaces.
* All the words in `s` are separated by a **single space**.