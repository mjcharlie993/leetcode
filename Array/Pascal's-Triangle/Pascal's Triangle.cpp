//Source : https://leetcode.com/problems/pascals-triangle/
//Author : Mao Jiachen
//Date   : 2016/12/08

/****************************************************************************************
 *
 * Arrpoach: Iteration
 * Algorithm: set a 2D-vector, and make the first one and the last one of every row set 1,
 * resize the every row as i + 1. Then using the Pascal`s triangle quality to fill to array.
 * Quality: triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j].
 *
 ****************************************************************************************/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        for (int i = 0; i < numRows; i++) {
		    triangle[i].resize(i + 1);
		    triangle[i][0] = triangle[i][i] = 1;
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }
};
