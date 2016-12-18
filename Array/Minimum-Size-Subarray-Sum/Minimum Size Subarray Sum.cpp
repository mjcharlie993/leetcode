//Source : https://leetcode.com/problems/minimum-size-subarray-sum/
//Author : Mao Jiachen
//Date   : 2016/12/18

/****************************************************************************************
 *
 * Approach: Two Pointer
 * Algorithm: remove the window and dynamic calculate the sum. 
 *
 ***************************************************************************************/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i != n; ++i) {
            sum += nums[i];
            while (sum >= s) {
                minlen = min(minlen, i - left + 1);
                sum -= nums[left++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};