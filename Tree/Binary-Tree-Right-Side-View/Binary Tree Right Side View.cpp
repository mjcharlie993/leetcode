//Source : https://leetcode.com/problems/binary-tree-right-side-view/
//Author : Mao Jiachen
//Date   : 2017/03/30

/********************************************************************
 * 
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t = nullptr;
        while (!q.empty()) {
            res.push_back(q.back()->val);
            int n = q.size();
            for (int i = 0; i < n; i++) {
                t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};