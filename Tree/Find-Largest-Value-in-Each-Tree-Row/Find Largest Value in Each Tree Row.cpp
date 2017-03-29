//Source : https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp = nullptr;
        while (!q.empty()) {
            int n = q.size();
            int maxNum = INT32_MIN;
            for (int i = 0; i < n; i++) {
                temp = q.front();
                q.pop();
                maxNum = max(maxNum, temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            res.push_back(maxNum);
        }
        return res;
    }
};
