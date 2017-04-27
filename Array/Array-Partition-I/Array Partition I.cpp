//Source : https://leetcode.com/problems/array-partition-i/
//Author : Mao Jiachen
//Date   : 2016/04/27

/****************************************************************************************
 *
 *
 ***************************************************************************************/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i != size; i += 2) {
            res += nums[i];
        }
        return res;
    }
};