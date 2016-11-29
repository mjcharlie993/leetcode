//Source: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
//Author: Mao Jiachen
//Data  : 2016/11/29

/***************************************************************************************
 *
 * Approach: Plus or Minus Notation 
 * step1. Traversal the nums and sign the numbers of appear as '-'.
 *        When you traversal the twice numbers,you should reset it to '+' and then sign
 *        it to '-'.(why use the abs)
 * step2. Now all the appeared of 1 to n(the size of nums) is '-', and the disappeared 
 *        number is '+'. Traversal the vector and find the '+' numbers. and put the(the 
 *        index + 1) to a new vector.
 *
 ***************************************************************************************/
 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto &i : nums) {
            int idx = abs(i) - 1;
            nums[idx] = -1 * abs(nums[idx]);
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) 
            if (nums[i] > 0)
                res.push_back(i + 1);
        return res;
    }
};
