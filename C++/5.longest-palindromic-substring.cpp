/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 * 
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * Example 2:
 * Input: "cbbd"
 * Output: "bb"
 */
class Solution {
public:
        void findPalidrome(string s, int left, int right, int& start, int& length)
    {
        while (left>=0 && right < s.size() && s.at(left) == s.at(right)) {
            left--;right++;
        }

        //注意right(+1)，left(-1)，所以需要-1。 附：求A到B：L=B-A+1
        int tmpLength = right - left - 1;
        
        if(length < tmpLength)
        {
            start = left+1;
            length = tmpLength;
        }
    }

    string longestPalindrome(string s) {
        if (s.size() < 2) return s;

        int pStart=0, pLength=0;
        for(int n=0;n<s.size()-1;n++)
        {
            findPalidrome(s, n, n, pStart, pLength);
            findPalidrome(s, n, n+1, pStart, pLength);
        }
        return s.substr(pStart, pLength);
    }
};

