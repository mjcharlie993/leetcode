//Source : https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<TreeNode*> s;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        s.push(root);
        while (!s.empty()) {
            cur = s.top();
            // 如果当前结点没有孩子结点 或者 孩子节点都已被访问过
            if ((cur->left == nullptr && cur->right == nullptr) || (pre != nullptr && (pre == cur->left || pre == cur->right))) {
                res.push_back(cur->val);
                s.pop();
                pre = cur;
            } else {
                if (cur->right != nullptr)
                    s.push(cur->right);
                if (cur->left != nullptr)
                    s.push(cur->left);
            }
        }
        return res;
    }
};