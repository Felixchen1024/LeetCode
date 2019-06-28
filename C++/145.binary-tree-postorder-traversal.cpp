/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 * 
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * Output: [3,2,1]
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root) {
            if(root->left) {
                vector<int> ret = postorderTraversal(root->left);
                res.insert(res.end(), ret.begin(), ret.end());
            }
            if(root->right) {
                vector<int> ret = postorderTraversal(root->right);
                res.insert(res.end(), ret.begin(), ret.end());
            }
            
            res.push_back(root->val);
        }
        return res;  
    }
};

