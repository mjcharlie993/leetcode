//Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
//Author : Mao Jiachen
//Date   : 2017/05/07

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<int> s;
        while (root != nullptr && !s.empty()) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
