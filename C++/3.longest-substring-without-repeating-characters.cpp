/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 * 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * Example 2:
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2)
            return s.size();
        
        unordered_map<char, int> m;
        int ans = 0;
        for(int i=0, j=0;i<s.size();i++) {
            char tmp = s.at(i);
            if(m.count(s.at(i))) {
                j = max(j, m[tmp]);
            }
            ans = max(ans, i-j+1);
            m[tmp] = i+1;
        }
        
        return ans;
    }
};

