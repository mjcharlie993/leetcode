//Source : https://leetcode.com/problems/climbing-stairs/
//Author : Mao Jiachen
//Data   : 2016/11/29

/***************************************************************************************
 * 
 * #1
 * Approach: Using vector save the last result.
 *
 * #2
 * Approach: Using 3 variables replace vector.
 *
 **************************************************************************************/
 
//#1
class Solution {
public:
    int climbStairs(int n) {
        if (n < 1)
            return 0;
        vector<int> res(n + 1, 1);
        for (int i = 2; i < n + 1; i++) 
            res[i] = res[i - 1] + res[i - 2];
        return res[n];
    }
};

//#2
class Solution {
public:
    int climbStairs(int n) {
        if (n < 1)
            return 0;
        int res0 = 1, res1 = 1, res2 = 1;
        for (int i = 2; i < n + 1; i++) {
            res0 = res1 + res2;
            res2 = res1;
            res1 = res0;
        }
        return res0;
    }
};
