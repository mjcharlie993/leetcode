//Source : https://leetcode.com/problems/summary-ranges/
//Author : Mao Jiachen
//Date   : 2017/03/16

/********************************************************************
 *
 * Algorithm: traversal one time array, if the next num is continuous
 * and go on, if not, judge the time the solution whether a number or 
 * a series. If the solution is a number, and save it to res array. 
 * If the solution is a series numbers, save it to res array by "->".
 * 
 *******************************************************************/

class solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) {
            int j = 1;
            while (i + j < n && nums[i + j] - nums[i] == j)
                ++j;
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return res;
    }
}