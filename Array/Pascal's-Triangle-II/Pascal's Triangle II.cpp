//Source : https://leetcode.com/problems/pascals-triangle-ii/
//Author : Mao Jiachen
//Date   : 2016/12/08

/**********************************************************************************************
 *
 * Approach: Iteration
 * Algorithm: Build a new result vector, set the size is rowIndex + 1 and set all the 
 * element is 1. Then replace the number in this array, Before the rowIndex layer, the every 
 * layer element is the res[j] = res[j] + res[j-1], So the last index of every row is j - 1,
 * the first index of every row is 1, calculate the every row element and use it to calculate
 * next row, and replace the element.
 * Finally return the rowIndex array.   
 *
 **********************************************************************************************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.resize(rowIndex + 1, 1);
        for (int i = 0; i < rowIndex + 1; i++) {
            for (int j = i - 1; j >= 1; j--) {
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};