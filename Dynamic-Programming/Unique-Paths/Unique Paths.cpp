//Source : https://leetcode.com/problems/unique-paths/
//Author : Mao Jiachen
//Date   : 2016/12/02

/****************************************************************************************
 *
 * Approach: Calculate by i, j;
 * Algorithm: Build a  a two-dimensional vector, save m and vector<int>(n). 
 * Set the first horizontal and vertical to 1, to there points will take one way.
 * Traversal this vector, and set f[i][j] = f[i-1][j] + f[i][j-1].                     
 * Finally return f[m-1][n-1];
 * For example: m = 7 n = 3.
 *
 *       n   1   2   3   4   5   6
 *       
 *   m   1   1   1   1   1   1   1   
 *          
 *   1   1   2   3   4   5   6   7
 *
 *   2   1   3   6   10  15  21  28
 *
 *
 ***************************************************************************************/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));
        for(int i = 0; i < n; i++)
            f[0][i] = 1;
        for(int i = 0; i < m; i++)
            f[i][0] = 1;
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                f[i][j] = f[i-1][j] + f[i][j-1];
        return f[m-1][n-1];
    }
};