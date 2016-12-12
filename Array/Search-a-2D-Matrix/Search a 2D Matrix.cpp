//Source : https://leetcode.com/problems/search-a-2d-matrix/
//Author : Mao Jiachen
//Date   : 2016/12/12

/****************************************************************************************
 *
 * Approach: Binary Search in Twice
 * Algorithm: Using binary search in row and col, and find the target. 
 * O(lgM + lgN)
 *
 ****************************************************************************************/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        int left = 0, right = M - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int row = right;
        if (row < 0)
            return false;
        left = 0;
        right = N - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};