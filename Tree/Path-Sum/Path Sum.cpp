//Source : https://leetcode.com/problems/path-sum/
//Author : Mao Jiachen
//Date   : 2017/05/11

/********************************************************************
 * 
 * This question is not required print the path, so we need judge path
 * sum.
 * Using two methods to solve this problem.
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
 
 // #1
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr && sum == root->val)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

// #2
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        stack<TreeNode*> path;
        bool hasPath = false;
        hasPathSumCore(root, sum, path, hasPath);
        return hasPath;
    }
    
    void hasPathSumCore(TreeNode* root, int sum, stack<TreeNode*>& path, bool& hasPath) {
        if (root == nullptr)
            return;
        path.push(root);
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (sum == root->val && isLeaf) {
            hasPath = true;
            return;
        }
        hasPathSumCore(root->left, sum - root->val, path, hasPath);
        hasPathSumCore(root->right, sum - root->val, path, hasPath);
        path.pop();
    }
};