//Source : https://leetcode.com/problems/missing-number/
//Author : Mao Jiachen
//Data   : 2016/12/01

/***************************************************************************************
 *
 * Approach: Subtraction
 * Algorithm: Becaues the given array is distinct numbers, it is an arithmetic sequence.
 * We should sum this array as A. Then we calculate the test array, sum this array as B. 
 * The number of A - B is the disappear number.
 *
 ***************************************************************************************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (auto i : nums)
            sum += i;
        return 0.5 * n * (n + 1) -sum;
    }
};