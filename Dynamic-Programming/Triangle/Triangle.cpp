//Source : https://leetcode.com/problems/triangle/
//Author : Mao Jiachen
//Date   : 2016/12/08

/****************************************************************************************
 *
 * Approach: Dynamic Programming
 * Algorithm: Calculating begin the lowest layer, and set the number to a new array, to
 * save the sum of step. Then begin to calculate the sum step, like the (i = row - 2)
 * sum[j] = triangle[i][j] + min(sum[j], sum[j+1]).
 * when the calculate  the top one. The sum[0] is including the top one, this is the final
 * route. So the sum[0] is the final return value.
 *
 ***************************************************************************************/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int row = triangle.size();
        vector<int> sum(row, 0);
        for (int i = 0; i < row; i++) {
            sum[i] = triangle[row-1][i];
        }
        for (int i = row-2; i >= 0; i--) 
            for (int j = 0; j <= i; j++) 
                sum[j] = triangle[i][j] + min(sum[j], sum[j+1]);
        return sum[0];
    }
};