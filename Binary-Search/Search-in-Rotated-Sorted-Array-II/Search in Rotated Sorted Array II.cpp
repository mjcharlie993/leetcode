//Source : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
//Author : Mao Jiachen
//Date   : 2016/12/02

/****************************************************************************************
 *
 * Approach: Binary search
 * Algorithm: Comparing the search in rotated sorted array, this way add the mid is equal 
 * to edge judgement. And make i++;
 * The Complexit is turned to o(n);
 *
 ****************************************************************************************/
 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return false;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[left]) {
                if (nums[left] <= target && nums[mid] > target) 
                    right = mid - 1;
                else
                    left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else    
                    right = mid - 1;
            } else {
                left++;
            }
        }
        return false;
    }
};