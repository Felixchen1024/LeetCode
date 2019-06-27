/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= 2 || numRows >= s.size() || numRows == 1)
            return s;
        
        vector<string> r(numRows);
        int row = 0;
        int step = 1;
        for(int n=0;n<s.size();n++)
        {
            if(row == numRows-1)
                step = -1;
            if(row == 0)
                step = 1;
            
            r[row] += s.at(n);
            row += step;
        }
        
        string res;
        for(int n=0;n<numRows;n++)
        {
            res += r.at(n);
        }
        return res;
    }
};

