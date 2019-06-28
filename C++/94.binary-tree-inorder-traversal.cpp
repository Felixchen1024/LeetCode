/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 * 
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root)
        {
            if(root->left)
            {
                vector<int> ret = inorderTraversal(root->left);
                res.insert(res.end(), ret.begin(), ret.end());
            }
            
            res.push_back(root->val);
                
            if(root->right)
            {
                vector<int> ret = inorderTraversal(root->right);
                res.insert(res.end(), ret.begin(), ret.end());
            }
        }
        return res;  
    }
};
