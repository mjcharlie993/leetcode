//Source : https://leetcode.com/problems/find-bottom-left-tree-value/
//Author : Mao Jiachen
//Date   : 2017/03/29

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

 // BFS
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (i == 0) res = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};

 // DFS
class Solution {
public:
    pair<int, int> res;
    int findBottomLeftValue(TreeNode* root) {
        res.first = 0;
        res.second = root->val;
        dfs(root, 0);
        return res.second;
    }
    void dfs(TreeNode* root, int level) {
        if (!root) return;
        if (level > res.first) {
            res.first = level;
            res.second = root->val;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};