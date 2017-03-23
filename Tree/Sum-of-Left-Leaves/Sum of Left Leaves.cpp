//Source : https://leetcode.com/problems/sum-of-left-leaves/
//Author : Mao Jiachen
//Date   : 2017/03/23

/********************************************************************
 * #1
 * #2
 * #3
 * #4
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

// #1
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || (!root->left && !root->right)) 
            return 0;
        int res = 0;
        helper(root->left, true, res);
        helper(root->right, false, res);
        return res;
    }

    void helper(TreeNode* node, bool left, int& res) {
        if (!node)
            return;
        if (!node->left && !node->right && left) 
            res += node->val;
        helper(node->left, true, res);
        helper(node->right, false, res);
    }
};

// #2
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        if (root->left && !root->left->left && !root->left->right) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

// #3
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (t->left && !t->left->left && !t->left->right )
                res += t->left->val;
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return res;
    }
};

// #4
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return 0;
        int res = 0;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            if (t->left && !t->left->left && !t->left->right)
                res += t->left->val;
            if (t->left) s.push(t->left);
            if (t->right) s.push(t->right);
        }
        return res;
    }
};