/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> res;
        if (root == nullptr)
            return;
        findPaths(root, res, to_string(root->val));
        return res;
    }

    void findPaths(TreeNode* root, vector<string>& res, string str) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(str);
            return;
        }
        if (root->left != nullptr)
            findPaths(root->left, res, str + "->" + to_string(root->left->val));
        if (root->right != nullptr)
            findPaths(root->right, res, str + "->" + to_string(root->right->val));
    }
};