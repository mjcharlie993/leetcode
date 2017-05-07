//Source : https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            if (root != nullptr) {
                s.push(root);
                res.push_back(root->val);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return res;
    }
};
