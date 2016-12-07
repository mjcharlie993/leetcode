//Source : https://leetcode.com/problems/two-sum/
//Author : Mao Jiachen
//Date   : 2016/12/07

/****************************************************************************************
 *
 * Approach: Doule Cycle
 * Algorithm: There are two for cycle, outside cycle is begin index 0 to index the one 
 * before last index, inside cycle is begin index 1 to the last index. If find the num`s
 * sum is equal to target, return their index.
 *  
 ***************************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = 1;
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {i, j};
    }
};