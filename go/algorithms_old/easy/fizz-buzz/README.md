# [412. Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)

## Description

Given an integer **n**, return _a string array `answer` **(1-indexed)** where_:
* `answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.
* `answer[i] == "Fizz"` if `i` is divisible by `3`.
* `answer[i] == "Buzz"` if `i` is divisible by `5`.
* `answer[i] == i` (as a string) if none of the above conditions are true.


**Example 1:**

```go
Input: n = 3
Output: ["1","2","Fizz"]
```

**Example 2:**

```go
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
```

**Example 3:**

```go
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
```

**Constraints:**
* `1 <= n <= 10^4`