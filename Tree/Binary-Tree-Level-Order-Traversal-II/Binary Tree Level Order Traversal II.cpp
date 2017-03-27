//Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
//Author : Mao Jiachen
//Date   : 2017/03/27

/********************************************************************
 * #1 34ms
 * #2 8ms
 *******************************************************************/

 //#1
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> curlayer;
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                curlayer.push_back(cur->val);
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            res.push_back(curlayer);
        }
        resverse(res.begin(), res.end());
        return res;
    }
};

 //#2
class Solution {
public:
    void levelOrder(vector<vector<int>>& ans, TreeNode* node, int level) {
        if (!node) return;
        if (level >= ans.size())
            ans.push_back({});
        ans[level].push_back(node->val);
        levelOrder(ans, node->left, level + 1);
        levelOrder(ans, node->right, level + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(ans, root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
