//Source : https://leetcode.com/problems/path-sum-ii/
//Author : Mao Jiachen
//Date   : 2017/05/11

/********************************************************************
 * 
 * This question is required save the path, so we need a vector to save
 * path, and then save all paths into a 2D vector
 * This solution likes 2nd of Path Sum.
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vv;
        vector<int> v;
        if (root == nullptr)
            return vv;
        pathSumCore(root, sum, vv, v);
        return vv;
    }
    
    void pathSumCore(TreeNode* root, int sum, vector<vector<int>>& vv, vector<int>& v) {
        if (root == nullptr)
            return;
        v.push_back(root->val);
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (sum == root->val && isLeaf) 
            vv.push_back(v);
        pathSumCore(root->left, sum - root->val, vv, v);
        pathSumCore(root->right, sum - root->val, vv, v);
        v.pop_back();        
    }
};