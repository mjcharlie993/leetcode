//Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> curlayer;
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                curlayer.push_back(cur->val);
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            res.push_back(curlayer);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};