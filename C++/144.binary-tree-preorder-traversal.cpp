/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 * 
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * Output: [1,2,3]
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root != nullptr)
        {
            res.push_back(root->val);
            if(root->left)
            {
                vector<int> ret = preorderTraversal(root->left);
                res.insert(res.end(), ret.begin(), ret.end());
            }    
            if(root->right)
            {
                vector<int> ret = preorderTraversal(root->right);
                res.insert(res.end(), ret.begin(), ret.end());
            }
        }
        return res;
    }
};

