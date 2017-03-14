//Source : https://leetcode.com/problems/max-consecutive-ones/
//Author : Mao Jiachen
//Date   : 2017/03/14

/*******************************************************************************
 *
 * Approach: Simple Question
 * Algorithm: first Traverse vector and use a counter to save the number, if the  
 * num is 0, put the cnt = 0, if the num is 1, put the cnt = cnt + 1, the update
 * the res. 
 *
 *******************************************************************************/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            cnt = (num == 0) ? 0 : cnt + 1;
            res = max(res, cnt);
        }
        return res;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, sum = 0;
        for (int num : nums) {
            sum = (num + sum) * num;
            res = max(sum, res);
        }
        return res;
    }
}