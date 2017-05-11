//Source : https://leetcode.com/problems/path-sum-iii/
//Author : Mao Jiachen
//Date   : 2017/05/11

/*************************************************************************
 * 
 * #1
 * The result path is not from root to leaf only, So we need update 
 * the current sum and judge the current sum with target sum.
 * the method of calculating current sum is traversaling path vector,
 * in every step, we first sub element is path[0], it is meaning the 
 * element is near root node. we need pay attention to retain the last
 * element of vector, becaues if you sub the last element, the current
 * sum is zero, if the target sum is zero too, we will get wrong result.
 *
 * #2
 * using hash table and reduce calculation
 *
 * #3
 * 
 *
 ************************************************************************/

// #1
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> path;
        pathSumCore(root, sum, 0, path, res);
        return res;
    }
    
    void pathSumCore(TreeNode* root, int sum, int curSum, vector<TreeNode*>& path, int& res) {
        if (root == nullptr)
            return;
        curSum += root->val;
        path.push_back(root);
        if (curSum == sum)
            res++;
        int temp = curSum;
        for (int i = 0; i != path.size() - 1; i++) {
            temp -= path[i]->val;
            if (temp == sum)
                res++;
        }
        pathSumCore(root->left, sum, curSum, path, res);
        pathSumCore(root->right, sum, curSum, path, res);
        path.pop_back();
    }
};

// #2
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        return pathSumCore(root, sum, 0, m);
    }

    int pathSumCore(TreeNode* root, int sum, int curSum, unordered_map<int, int>& m) {
        if (root == nullptr)
            return 0;
        curSum += root->val;
        int res = m[curSum - sum];
        m[curSum]++;
        res += pathSumCore(root->left, sum, curSum, m) + pathSumCore(root->right, sum, curSum, m);
        m[curSum]--;
        return res;
    }
};

// #3
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int sumUp(TreeNode* node, int pre, int& sum) {
        if (!node) return 0;
        int cur = pre + node->val;
        return (cur == sum) + sumUp(node->left, cur, sum) + sumUp(node->right, cur, sum);
    }
};