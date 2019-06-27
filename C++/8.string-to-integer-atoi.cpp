/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 * 
 * Implement atoi which converts a string to an integer.
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 * 
 * Example 1:
 * Input: "42"
 * Output: 42
 * 
 * Example 2:
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus sign.
 * Then take as many numerical digits as possible, which gets 42.
 * 
 * Example 3:
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
 * 
 * Example 4:
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a numerical 
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * 
 * Example 5:
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
 * Thefore INT_MIN (−231) is returned.
 */
class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) //空字符串
            return 0;

        int n=0, pre_n=0; //索引，上一次索引
        int symbol = 1; //符号
        int symbol_cnt = 0; //符号计数，解决前置多个符号的问题
        long res = 0; //返回值，long类型才能计算超过INT范围的情况
        bool frist = true; //第一次找到数字标志
        while(n < str.size()) //遍历
        {
            char c = str.at(n); //读取第n个字符
            if(frist) //还未找到数字的情况下，遇到其他字符，则返回0
            {
                if(!(c == ' '|| c == '-'|| c == '+'|| (c >= '0'&& c <= '9')))
                    break;
            }

            if(c == ' ' && (symbol_cnt != 0 || pre_n != 0)) //数字中间遇到空格，则打断
                break;

            if(c == '-' && pre_n == 0) //没有找到数字的情况下，找到负号
            {
                if(symbol_cnt == 0) //第一次找到符号
                    symbol = -1;
                symbol_cnt++; //符号计数
            }
            if(c == '+' && pre_n == 0) //没有找到数字的情况下，找到正号
            {
                if(symbol_cnt == 0) //第一次找到符号
                    symbol = 1;
                symbol_cnt++; //符号计数
            }

            if(symbol_cnt > 1) //找到多个符号，则打断
                break;

            if(c >= '0' && c <= '9') //找到数字
            {
                if((frist) || n-pre_n == 1) //第一次找到时不满足n-pre_n==1，所以增加第一次标志位，n-pre_n==1保证连续找到
                {
                    frist = false; //第一次找到数字标志置为false
                    res = res*10 + c-'0'; //转为数字
                    if(res*symbol > INT_MAX) //超过限制
                        return INT_MAX;
                    if(res*symbol < INT_MIN) //超过限制
                        return INT_MIN;
                    pre_n = n;
                }
                else
                    break;

            }
            n++;
        }
        return int(res*symbol);
    }
};

