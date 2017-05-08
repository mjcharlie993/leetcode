//Source : https://leetcode.com/problems/binary-tree-paths/
//Author : Mao Jiachen
//Date   : 2017/05/08

/********************************************************************
 * #1 Iteration
 *******************************************************************/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr)
            return res;
        findPaths(root, res, to_string(root->val));
        return res;
    }
    
    void findPaths(TreeNode* root, vector<string>& res, string str) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(str);
            return;
        }
        if (root->left != nullptr)
            findPaths(root->left, res, str + "->" + to_string(root->left->val));
        if (root->right != nullptr)
            findPaths(root->right, res, str + "->" + to_string(root->right->val));
    }
};