/*
 * @lc app=leetcode id=49 lang=java
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms Medium (69.98%) Likes: 19949 Dislikes: 662 Total Accepted: 3.4M Total Submissions:
 * 4.9M Testcase Example: '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return the answer in any
 * order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * 
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * Explanation:
 * 
 * 
 * There is no string in strs that can be rearranged to form "bat". The strings "nat" and "tan" are
 * anagrams as they can be rearranged to form each other. The strings "ate", "eat", and "tea" are
 * anagrams as they can be rearranged to form each other.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = [""]
 * 
 * Output: [[""]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: strs = ["a"]
 * 
 * Output: [["a"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4 0 <= strs[i].length <= 100 strs[i] consists of lowercase English
 * letters.
 * 
 * 
 */

import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;

// @lc code=start
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            // Convert the string to a character array and sort it.
            char[] t = s.toCharArray();
            Arrays.sort(t);
            // Create a new string from the sorted character array as the key.
            String k = String.valueOf(t);
            // If the sorted string key is not present in the map, initialize the list.
            // Then add the original string to the list associated with the sorted string key.
            map.computeIfAbsent(k, _ -> new ArrayList<>()).add(s);
        }

        return new ArrayList<>(map.values());

    }
}
// @lc code=end
