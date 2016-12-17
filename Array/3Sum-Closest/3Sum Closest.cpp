//Source : https://leetcode.com/problems/3sum-closest/
//Author : Mao Jiachen
//Date   : 2016/12/17

/****************************************************************************************
 *
 * Approach: Two Pointer
 * Algorithm: First sorted the vector, and traversal vector, using two point set the 
 * l = i + 1, r = n - 1, if the dis (target - sum) is less than mindis, set the sum as 
 * result, dis as the mindis, then if the sum < target, set the l plus one, else set 
 * the r plus one. If the sum is equal to target, return to res, and break the for cycle
 *
 ***************************************************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0, mindis = INT32_MAX;
        for (int i = 0; i != n - 2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int dis = abs(target - sum);
                if (mindis > dis) {
                    res = sum;
                    mindis = dis;
                } else if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    return res;
                }
            }
        }
        return res;
    }
};