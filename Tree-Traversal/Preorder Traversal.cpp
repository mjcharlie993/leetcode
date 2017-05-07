vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)
        return res;
    stack<TreeNode*> s;
    while (root != nullptr || !s.empty()) {
        if (root != nullptr) {
            s.push(root);
            res.push_back(root->val);
            root = root->left;
        } else {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    return res;
}