//Source : https://leetcode.com/problems/rotate-image/
//Author : Mao Jiachen
//Date   : 2016/12/07

/***********************************************************************************************
 *
 * #1
 * Approach: Calculate New Index
 * Algorithm: calculate the new vector's number index, and replace it.

 * #2
 * Approach: Transposition and Reverse
 * Algorithm: First inside cycle making the first row transposited and reverse it. Then 
 * set the outside cycle number plus one. Just like first cycle, it make the second row
 * transposited and reverse. Until turn to the outside n th. The new vector has been finished. 
 * 
 ***********************************************************************************************/

 //#1
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
         for (int i = 0; i < n / 2; i++) {
             for (int j = i; j < n - 1 - i; j++) {
                 int temp = matrix[i][j];
                 matrix[i][j] = matrix[n-1-j][i];
                 matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                 matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                 matrix[j][n-1-i] = temp;
             }
         }
    }
};    

 //#2
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
         for (int i = 0; i < n; i++) {
             for (int j = i + 1; j < n; j++) {
                 swap(matrix[i][j], matrix[j][i]);
             }
             reverse(matrix[i].begin(), matrix[i].end());
         }
    }
};
