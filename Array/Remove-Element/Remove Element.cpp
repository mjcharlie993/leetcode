//Source : https://leetcode.com/problems/remove-element/
//Author : Mao Jiachen
//Date   : 2016/12/01

/*******************************************************************************
 * 
 * #1
 * Approach: Two Pointers
 * Algorithm: When nums[i] equals to the given value, skip this element by
 * increamenting i. As long as nums[i] != val, we copy nums[i] to nums[res]
 * and increment both indexes at the same time. Pepeat the process until i
 * reaches the end of the array and the new length is res;
 * 
 * #2
 * Approach: Two pointers - When elements to remove are rare
 * Algorithm: When we encounter nums[i] = val, we can swap the current element
 * out with the last element and dispose the last one. This essentially  reduces
 * the array's size by 1.
 * Note that the last element that was swapped in could be the value you want
 * to remove itself. But don't worry, in the next iteration we will still check 
 * this element.
 *

 *******************************************************************************/

 //#1
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) 
            if (nums[i] != val)
                nums[res++] = nums[i];
        return res;
    }
};


 //#2
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                //reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};