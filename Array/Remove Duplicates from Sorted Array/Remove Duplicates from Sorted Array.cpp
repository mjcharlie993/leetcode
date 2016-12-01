//Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//Author : Mao Jiachen
//Data   : 2016/12/01

/***********************************************************************************************
 *
 * Approach: Two Pointers
 * Algorithm: Since the array is already sorted, we can keep two pointers res and i, where res is 
 * the slow-runner while i is the fast-runner. As long as nums[res] = nums[i], we increment i to 
 * skip the duplicate. 
 * When we encounter nums[res] != nums[i], the duplicate run has ended so we must copy its value
 * to nums[res+1]. res is then incremented and we repeat the same process again until i reaches 
 * the end of array.
 *
 ***********************************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] != nums[i]) {
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }
};