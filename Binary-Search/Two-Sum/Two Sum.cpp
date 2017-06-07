//Source : https://leetcode.com/problems/two-sum/
//Author : Mao Jiachen
//Date   : 2017/06/06

/****************************************************************************************
 *
 * Approach1: Binary Search
 *
 ***************************************************************************************/

// #1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i = 0; i != nums.size(); i++)
            m[nums[i]] = i;
        for (int i = 0; i != nums.size(); i++) {
            int tmp = target - nums[i];
            if (m.count(tmp) && m[tmp] != i) {
                res.push_back(i);
                res.push_back(m[tmp]);
                break;
            }
        }
        return res;
    }
};
