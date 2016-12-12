//Source : https://leetcode.com/problems/set-matrix-zeroes/
//Author : Mao Jiachen
//Date   : 2016/12/12

/***********************************************************************************************
 *
 * Approach: Set Flag and Traversal vector
 * Algorithm: Set the rowflag and colflag of the first row and col. Then traversal the 
 * 2D vector except the first row and col. If the matrix[i][j] == 0, setting the matrix[i][0]
 * and matrix[0][j] to 0. Traversal the vector second time, using the matrix[i][0] and matrix[0][j], 
 * and set the matrix[i][j] to 0. 
 * Finally consider the flag of row and col, and set the line of it to 0.
 * 
 * This is the best way to solve this program, it using a constant space. 
 * 
 ***********************************************************************************************/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool rowFlag = false, colFlag = false;
        for (int i = 0; i != col; ++i) {
            if (matrix[0][i] == 0) {
                rowFlag = true;
                break;
            }
        }
        for (int i = 0; i != row; ++i) {
            if (matrix[i][0] == 0) {
                colFlag = true;
                break;
            }
        }
        for (int i = 1; i != row; ++i) {
            for (int j = 1; j != col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i != row; ++i) {
            for (int j = 1; j != col; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (rowFlag) {
            for (int i = 0; i != col; ++i) 
                matrix[0][i] = 0;
        }
        if (colFlag) {
            for (int i = 0; i != row; ++i) 
                matrix[i][0] = 0;
        }
    }
};