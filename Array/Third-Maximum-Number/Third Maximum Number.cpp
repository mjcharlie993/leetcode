//Source : https://leetcode.com/problems/third-maximum-number/
//Author : Mao Jiachen
//Data   : 2017/01/07

/****************************************************************************************
 *
 * Approach: Compare 3 Var 
 * Algorithm: use 3 var to save the first, second, third big number. and traversal vector
 * if the num is bigger than first, adjust to 3 var's value, if the num is between first
 * and second, adjust the second and third value, if the num is between second and third,
 * make third = num. 
 * Finally, consider the third value, if the nums.size = 2, the third = init_value,else if 
 * nums.size = 1, the second = init_value, so return the first. 
 *
 ***************************************************************************************/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num > third && num < second) {
                third = num;
            }
        }
        return (third == LONG_MIN || third == second) ? first : third;
    }
};