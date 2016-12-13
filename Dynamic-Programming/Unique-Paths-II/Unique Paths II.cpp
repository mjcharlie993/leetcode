//Source : https://leetcode.com/problems/unique-paths-ii/
//Author : Mao Jiachen
//Date   : 2016/12/13

/*********************************************************************************************
 *
 * Approach: Dynamic Programming
 * Algorithm: Build a new res vector to save the result. when you traversal the obstacleGrid = 1
 * you should set the res[j] = 0. Just like there is no way to across. 
 * In other time, make the res[j] = res[j] + res[j-1]. 
 *
 *********************************************************************************************/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<int> res(col, 0);
        res[0] = 1;
        for (int i = 0; i != row; ++i) {
            for (int j = 0; j != col; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    res[j] = 0;
                } else {
                    if (j > 0) {
                        res[j] += res[j-1];
                    }
                }
            }
        }
        return res[col-1];
    }
};