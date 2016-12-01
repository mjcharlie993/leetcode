//Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//Author : Mao Jiachen
//Data   : 2016/12/01

/****************************************************************************************
 *
 * Approach: Binary Search
 * Algorithm: build a temp variable to save result of two numbers addition.
 * The left number begins to the head of array, the right number begins to the tailer of 
 * array. In fact, the array is sorted. If temp number is less than target, we can judge 
 * the left number is smaller than require number, we should make the left number`s index
 * plus + 1 for turning next number. On the contrary, If temp number is more than target,
 * it explain the right is bigger than require number, we should sub 1 to the right number`s 
 * index. If the temp number is equal to target, now the two numbers is the require numbers,
 * we should add this position(index + 1) to new array.
 *
 ***************************************************************************************/
 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> res;
        int temp = 0;
        while (left < right) {
            temp = numbers[left] + numbers[right];
            if (temp == target) {
                res.push_back(left + 1);
                res.push_back(right + 1);
                return res;
            } else if (temp < target) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};
