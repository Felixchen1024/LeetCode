/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 * 
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 * 
 * Example 1:
 * Input: 121
 * Output: true
 * 
 * Example 2:
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * 
 * Example 3:
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 * 
 * Follow up:
 * Coud you solve it without converting the integer to a string?
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x >= INT_MAX || x <= INT_MIN)
            return false;
        int tmp = x;
        int rx = 0;
        while(tmp > 0)
        {
            rx = rx*10 + tmp%10;
            tmp /= 10;
        }
        return (x == rx)?true:false;
    }
};

