//Source : https://leetcode.com/problems/find-peak-element/
//Author : Mao Jiachen
//Date   : 2016/12/07

/****************************************************************************************
 *
 * #1
 * Approach: Binary Search
 * Algorithm: Using Binary search and if the mid < mid + 1, it explain that the peak exist
 * the right direct of mid, set the left = mid + 1, If the mid > mid + 1, explaining the 
 * peak number is exist the left of mid, set the right = mid. 
 * Finally return the right.
 * 
 * #2
 * Approach: Traversal the Nums.
 * Algorithm: Traversaling from the index of one. If this number is less than the before 
 * number of it, this before number is the peak element, else make the index plus one.
 * if the array is the increament array, the last number is peak element.
 *
 ***************************************************************************************/

 //#1
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};

 //#2
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) return i - 1;
        }
        return nums.size() - 1;
    }
};