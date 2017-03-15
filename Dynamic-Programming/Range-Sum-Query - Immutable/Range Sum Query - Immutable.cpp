//Source : https://leetcode.com/problems/range-sum-query-immutable/
//Author : Mao Jiachen
//Date   : 2017/03/15

/********************************************************************
 *
 * ...
 * 
 *******************************************************************/

class NumArray {
public:
    NumArray (vector<int> nums) {
        if (nums.empty()) return;
        sum.push_back(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            sum.push_back(sum[i - 1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return sum[j] - sum[i - 1];
    }
private:
    vector<int> sum;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i, j);
 */