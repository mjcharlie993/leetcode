//Source : https://leetcode.com/problems/merge-sorted-array/
//Author : Mao Jiachen
//Date   : 2016/12/13

/****************************************************************************************
 * Approach: Two Pointer
 * Algorithm: Because the number of elements initialized in nums1 and nums2 are m and n 
 * respectively. we should traversal the nums1 and nums2 from tailer to header. and add
 * the result to num1 array. 
 * 
 ***************************************************************************************/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1, idx = m + n - 1;
        while (idx1 >= 0 && idx2 >= 0) {
            if (nums1[idx1] > nums2[idx2]) {
                nums1[idx--] = nums1[idx1--];
            } else {
                nums1[idx--] = nums2[idx2--];
            }
        }
        while (idx2 >= 0) {
            nums1[idx--] = nums2[idx2--];
        }
    }
};