//Source : https://leetcode.com/problems/rotate-array/
//Author : Mao Jiachen
//Date   : 2016/11/29

/***************************************************************************************
 *
 * Approach: Using Reverse  
 * 
 * This approach is based on the fact that when we rotate the array k times, 
 * k elements from the back end of the array come to the front and the rest of the 
 * elements from the front shift backwards.
 *
 * In this approach, we firstly reverse all the elements of the array.
 * Then, reversing the first k elements followed by reversing the rest n-k elements gives
 * us the required result.
 *
 * Let n = 7 and k = 3.
 *
 * Original array                   : 1 2 3 4 5 6 7
 * After reversing all numbers      : 7 6 5 4 3 2 1 
 * After reversing first k numbers  : 5 6 7 4 3 2 1
 * After reversing last n-k numbers : 5 6 7 1 2 3 4 --> result
 *
 ***************************************************************************************/
 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k &= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
};
    
