//Source : https://leetcode.com/problems/product-of-array-except-self/
//Author : Mao Jiachen
//Data   : 2016/12/01

/***************************************************************************************
 *
 * Approach: Construct Two Array
 * Algorithm: 
 * Input  : nums = [a1,       a2,       a3,       a4      ].
 * Output : res =  [a2*a3*a4, a1*a3*a4, a1*a2*a4, a2*a3*a4].
 * Build two array and multiply them. The two array like this:
 * 1. [1,        a1,    a1*a2, a1*a2*a3] res.
 * 2. [a2*a3*a4, a3*a4, a4,    1       ]
 * Using pro to save every calculation result.
 * First 'for cycle' is to construct the No.1 array.
 * Last 'for cycle' is to calculate the multiply of two array.
 * res[3] = a1*a2*a3.    res[2] = a1*a2*a4.    res[1] = a1*a3*a4.    res[0] = a2*a3*a4.  
 * Finally, return the First res array.
 * 
 ****************************************************************************************/
 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int pro = 1;
        for (int i = 0; i < n; i++) {
            res[i] = pro;
            pro *= nums[i];
        }
        pro = 1;
        for (int i = n - 1; i < n; i--) {
            res[i] *= pro;
            pro *= nums[i];
        }
        return res;
    }
};
