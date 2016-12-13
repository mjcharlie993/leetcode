//Source : https://leetcode.com/problems/search-for-a-range/
//Author : Mao Jiachen
//Date   : 2016/12/13

/****************************************************************************************
 *
 * Approach: Binary Search
 * Algorithm: Using two times binary search and find the target left edge and right edge.
 * return the index of the target range. 
 * 
 ***************************************************************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int ll = 0, lr = nums.size() - 1;
        while (ll <= lr) {
            int mid = (ll + lr) / 2;
            if (nums[mid] < target) {
                ll = mid + 1;
            } else {
                lr = mid - 1;
            }
        }
        int rl = 0, rr = nums.size() - 1;
        while (rl <= rr) {
            int mid = (rl + rr) / 2;
            if (nums[mid] <= target) {
                rl = mid + 1;
            } else {
                rr = mid - 1;
            }
        }
        if (ll <= rr) {
            res[0] = ll;
            res[1] = rr;
        }
        return res;
    }
};