//Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
//Author : Mao Jiachen
//Date   : 2016/12/02

/****************************************************************************************
 *
 * Approach: Binary Search 
 * Algorithm: In rotated sorted array, judge the nums[mid] and nums[left(right)], if the 
 * mid number < right number, it means the right of mid is sorted. On the contrary, if 
 * the mid number > right number, it means the left of mid is sorted. Then we should judge
 * the target whether is between the mid and right(left and mid). 
 * In this method, we will find the target in the array.
 * 
 * Notice: In the question, if we find the target in the array, we should return its index
 * But in the OJ, this is return none.
 *
 ***************************************************************************************/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};