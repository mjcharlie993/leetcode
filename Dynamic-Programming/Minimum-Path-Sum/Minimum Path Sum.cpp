//Source : https://leetcode.com/problems/minimum-path-sum/
//Author : Mao Jiachen
//Date   : 2016/12/11

/****************************************************************************************
 *
 * #1
 * Approach: 2D vector
 * Algorithm: Calculate the given 2D vector M, N. Set a new 2D vector to save the result 
 * number. First save just arcoss M and N needing how many step. Now we know the edge of  
 * result vector. So we calculate rest of the result vector. The next 
 * res[i][j] = grid[i][j] + min(res[i-1][j], res[i][j-1]). Using it fill with the vector
 * finally return the last one of the result vector res[M-1][N-1];

 * #2
 * Approach: 1D vector
 * Algorithm: Using res[j] to save the last one result before next step.
 * 
 ***************************************************************************************/

 //#1
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        vector<vector<int>> res(M, vector<int>(N, 0));
        res[0][0] = grid[0][0];
        for (int i = 1; i != M; ++i) {
            res[i][0] = grid[i][0] + res[i-1][0];
        }
        for (int j = 1; j != N; ++j) {
            res[0][j] = grid[0][j] + res[0][j-1];
        }
        for (int i = 1; i != M; ++i) {
            for (int j = 1; j != N; ++j) {
                res[i][j] = grid[i][j] + min(res[i][j-1], res[i-1][j]);
            }
        }
        return res[M-1][N-1];
    }
};

 //#2
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        vector<int> res(N, INT_MAX);
        res[0] = 0;
        for (int i = 0; i != M; ++i) {
            res[0] =  res[0] + grid[i][0];
            for (int j = 1; j != N; ++j) {
                res[j] = grid[i][j] + min(res[j], res[j - 1]);
            }
        }
        return res[N - 1];
    }
};