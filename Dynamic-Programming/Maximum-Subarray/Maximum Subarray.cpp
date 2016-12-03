//Source : https://leetcode.com/problems/maximum-subarray/
//Author : Mao Jiachen
//Date   : 2016/12/03

/****************************************************************************************
 *
 * Approach: Global and Local Optimal
 * ALgorithm: In every step we need keeping two variables Local and Global.
 * Global: The most optimal solution until current element.
 * Local: The most optimal solution include current element.
 * There are two dynamic Programming expression in a cycle.
 * Assume in No.i global[i], local[i].
 * In No.1+1, local[i] = max(A[i], local[i] + A[i]);  
 *            global[i + 1] = max(local[i + 1], global[i]);
 * 
 ***************************************************************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int global = nums[0];
        int local = nums[0];
        for (int i = 1; i < n; i++) {
            local = max(nums[i], local + nums[i]);
            global = max(local, global);
        }
        return global;
    }
};