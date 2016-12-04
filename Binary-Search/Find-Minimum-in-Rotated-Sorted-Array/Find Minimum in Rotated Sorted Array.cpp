//Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//Author : Mao Jiachen
//Date   : 2016/12/04

/****************************************************************************************
 *
 * Approach: Binary Search
 * Algorithm: Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * Using the binary search. It's a rotated sorted array, So judge the nums[mid] and 
 * nums[left]. If the nums[left] < nums[mid], you can judge the left to mid is sorted. 
 * Set the minimum between nums[left] and imin assumed before. Then set the left is equal
 * to mid plus one. On the contrary, if the nums[left] > nums[mid], you can judge the  
 * mid to right is sorted. Set the minimum between nums[mid] and imin assumed before. Then
 * set the right is equal to mid - 1. 
 * Finally, compare the minimum above imin, nums[left] and nums[right].
 * 
 ****************************************************************************************/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return n;
        int left = 0;
        int right = n - 1;
        int imin = nums[0];
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[left] < nums[mid]) {
                imin = min(nums[left], imin);
                left = mid + 1;
            } else if (nums[left] > nums[mid]) {
                imin = min(nums[mid], imin);
                right = mid - 1;
            }
        }
        imin = min(nums[right], imin);
        imin = min(nums[left], imin);
        return imin; 
    }
};