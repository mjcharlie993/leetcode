//Source : https://leetcode.com/problems/search-insert-position/
//Author : Mao Jiachen
//Date   : 2016/12/02

/****************************************************************************************
 *
 * Approach: Binary Search
 * Algorithm: Like classic binary search, but in this method. If the nums[mid] < target.
 * Set left = mid + 1. This means return left is correct. On the contrary
 * Set right = mid - 1.
 *
 ***************************************************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else    
                right = mid - 1;
        }
        return left;
    }
};