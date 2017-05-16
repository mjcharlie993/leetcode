//Source : https://leetcode.com/problems/reshape-the-matrix/
//Author : Mao Jiachen
//Date   : 2017/05/16

/*************************************************************************
 *
 * The core is the rows and columns of original matrix transform to new 
 * matrix
 *
 *************************************************************************/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rr = nums.size();
        int cc = nums[0].size();
        if (rr * cc != r * c)
            return nums;
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i != rr; i++) {
            for (int j = 0; j != cc; j++) {
                int k = i * cc + j;
                res[k / c][k % c] = nums[i][j];
            }
        }
        return res;
    }
};