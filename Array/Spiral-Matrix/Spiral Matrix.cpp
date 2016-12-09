//Source : https://leetcode.com/problems/spiral-matrix/
//Author : Mao JIachen
//Date   : 2016/12/09

/****************************************************************************************
 *
 * Approach: Add the element from outside loop to inside loop
 * Algorithm: First add the loop element, and judge the edge condition. If the judge is 
 * false, break the while cycle and return the result array. 
 * 
 ****************************************************************************************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int rowBegin = 0, rowEnd = matrix[0].size() - 1;
        int colBegin = 0, colEnd = matrix.size() - 1;
        while (1) {
            // left -> right
            for (int i = rowBegin; i <= rowEnd; ++i) 
                res.push_back(matrix[colBegin][i]);
            if (++colBegin > colEnd)
                break;
            // top -> bottom
            for (int i = colBegin; i <= colEnd; ++i)
                res.push_back(matrix[i][rowEnd]);
            if (rowBegin > --rowEnd)
                break;
            // right -> left
            for (int i = rowEnd; i >= rowBegin; --i)
                res.push_back(matrix[colEnd][i]);
            if (colBegin > --colEnd)
                break;
            // bottom -> top
            for (int i = colEnd; i >= colBegin; --i)
                res.push_back(matrix[i][rowBegin]);
            if (++rowBegin > rowEnd)
                break;
        }
        return res;
    }
};