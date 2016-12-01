//Source : https://leetcode.com/problems/majority-element/
//Author : Mao Jiachen
//Date   : 2016/12/01

/*******************************************************************************
 *
 * Approach: Find The Duplicate And Count It
 * Algorithm: Assume the elem is the majority element, count is the number appear
 * times. Traversal array if the count is 0, reset the new majority element and 
 * count as 1. 
 * Finally, If the count != 0, the elem is the majority element.
 * 
 ******************************************************************************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                elem = nums[i];
                count = 1;
            } else {
                if (elem == nums[i])
                    count++;
                else
                    count--;
            }
        }
        return elem;
    }
};