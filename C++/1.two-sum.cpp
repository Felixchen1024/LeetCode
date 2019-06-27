/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 * 
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;       
        unordered_map<int, int> m;
        for(int n=0;n<nums.size();n++) {
            int tmp = target - nums[n];
            if(m.count(tmp) && m[tmp] != n) {
                res.push_back(m[tmp]);
                res.push_back(n);
                break;
            }
            else {
                m[nums[n]] = n;
            }
        }
        return res;
    }
};

