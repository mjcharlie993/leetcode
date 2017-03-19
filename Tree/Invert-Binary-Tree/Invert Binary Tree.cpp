//Source : https://leetcode.com/problems/invert-binary-tree/
//Author : Mao Jiachen
//Date   : 2017/03/19

/********************************************************************
 *
 * #1
 * Approach: Using Recursion Solution
 *
 * #2
 * Approach: Using non-Recursion Solution
 *
 ********************************************************************/

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
class solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) 
            return nullptr;
        TreeNode* nlNode = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(nlNode);
        return root;
    }
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            invertTree(root->left);
            invertTree(root->right);
            std::swap(root->left, root->right);
        }
        return root;
    }
};

// #2
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* p = stk.top();
            stk.pop();
            if (p) {
                stk.push(p->left);
                stk.push(p->right);
                std::swap(p->left, p->right);
            }
        }
        return root;
    }
};