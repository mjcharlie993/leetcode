//Source : https://leetcode.com/problems/spiral-matrix-ii/
//Author : Mao Jiachen
//Date   : 2016/12/09

/****************************************************************************************
 *
 * Approach: Set number by cycing loop
 * Algorithm : Just like Spiral Matrix.
 *
 ***************************************************************************************/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> res(n, vector<int>(n, 0));
	int rowBegin = 0, rowEnd = n - 1;
	int colBegin = 0, colEnd = n - 1;
    int elem = 1;
	while (rowBegin <= rowEnd && colBegin <= colEnd) {
		for (int i = rowBegin; i <= rowEnd; i++)
			res[colBegin][i] = elem++;
		++colBegin;
		
		for (int i = colBegin; i <= colEnd; i++)
			res[i][rowEnd] = elem++;
		--rowEnd;
		
		for (int i = rowEnd; i >= rowBegin; --i)
			res[colEnd][i] = elem++;
		--colEnd;
			
		for (int i = colEnd; i >= colBegin; --i)
			res[i][rowBegin] = elem++;
		++rowBegin;
	}
	return res;
    }
};