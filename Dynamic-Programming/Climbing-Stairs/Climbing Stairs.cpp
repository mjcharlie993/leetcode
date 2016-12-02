//Source : https://leetcode.com/problems/climbing-stairs/
//Author : Mao Jiachen
//Date   : 2016/11/29

/***************************************************************************************
 * 
 * This subject is a dp question. Likes fib, monkey pick banans.
 * The TLE way is fib recursion.
 * So we use the tail recursion solve this question.
 * 
 * 1.State          : res[i]
 * 2.Function       : res[i] = res[i-1] + res[i-2]
 * 3.Initialization : res[0] = 1, res[1] = 1
 * 4.Answer         : res[n]
 *
 * In order to turn res[i], there are two process.
 * No.1: res[i-1], in this way the total methods don`t have change.
 * No.2: res[i-2], from res[i-2] to res[i], this way have 2 methods like 1+1 and 2.
 * Using No.1 result. The mid process res[i-1] had been used.
 * So the final function is res[i] = res[i-1] + res[i-2]
 *
 * Warning: In No.2, we must care for the duplication process!
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
