//Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
//Author : Mao Jiachen
//Date   : 2016/12/13

/****************************************************************************************
 *
 * Approach: Two Pointer
 * Algorithm: Because the duplicates are allowed at most twice. So when we will meet 3
 * same elements. we should set a temp var to save the covered element. 
 *
 ***************************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int idx = 1, temp = nums[idx];
        for (int i = 2; i != n; ++i) {
            if (nums[i] != nums[i-2]) {
                nums[idx++] = temp;
                temp = nums[i];
            }
        }
        nums[idx++] = temp;
        return idx;
    }
};