//Source : https://leetcode.com/problems/contains-duplicate/
//Author : Mao Jiachen
//Date   : 2016/12/01

/**********************************************************************************
 *
 * Approach: Sorting 
 * Algorithm: This approach employs sorting algorithm. Since comparison sorting 
 * algorithm like heapsort is known to provide o(nlogn) worst-case perfornabce,
 * sorting is often a good preprocessing step. After sorting, we can sweep the 
 * sorted array to find if there are any two consecutive duplicate elements.
 *
 *********************************************************************************/



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};