#pragma once

#include <stack>
#include <string>
#include <unordered_map>

using std::stack;
using std::string;
using std::unordered_map;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  bool isValid(string s) {
    // Map closing brackets to their corresponding opening brackets
    unordered_map<char, char> brackets = {{')', '('}, {']', '['}, {'}', '{'}};

    stack<char> st;

    for (char c : s) {
      // If it's a closing bracket
      if (brackets.contains(c)) {
        // Check if stack is empty or top doesn't match
        if (st.empty() || st.top() != brackets[c]) {
          return false;
        }
        st.pop();
      } else {
        // It's an opening bracket, push to stack
        st.push(c);
      }
    }

    // Valid if stack is empty (all brackets matched)
    return st.empty();
  }
};
