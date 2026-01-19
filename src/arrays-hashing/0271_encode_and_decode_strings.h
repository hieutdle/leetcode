#pragma once

#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

class Codec {
 public:
  // Time: O(n) | Space: O(n)
  // Encodes a list of strings to a single string.
  // Format: length + delimiter + string for each string
  string encode(vector<string>& strs) {
    string res;
    for (const auto& str : strs) {
      // " #" is a string literal, which is effectively a pointer (const char*)
      // str.size() returns an integer (size_t).
      res += to_string(str.size()) + "#" + str;
    }
    return res;
  }

  // Time: O(n) | Space: O(n)
  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> res;
    int i = 0;

    while (i < s.size()) {
      // Find the delimiter
      int delimiter_pos = s.find('#', i);
      // Extract the length
      int length = stoi(s.substr(i, delimiter_pos - i));
      // Move past the delimiter
      i = delimiter_pos + 1;
      // Extract the string using the length
      res.push_back(s.substr(i, length));
      // Move to the next encoded string
      i += length;
    }

    return res;
  }
};
