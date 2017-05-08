//Source : http://lintcode.com/zh-cn/problem/binary-tree-zigzag-level-order-traversal/
//Author : Mao Jiachen
//Date   : 2017/05/08

/********************************************************************
 * #1 Iteration
 *******************************************************************/


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
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> curlayer;
            for (int i = 0; i != size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                curlayer.push_back(cur->val);
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            if (flag)
                reverse(curlayer.begin(), curlayer.end());
            flag = !flag;
            res.push_back(curlayer);
        }
        return res;
    }
};