//Source : https://leetcode.com/problems/sqrtx/
//Author : Mao Jiachen
//Date   : 2017/06/08

/****************************************************************************************
 *
 ***************************************************************************************/

class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;
            if (sq == x)
                return mid;
            else if (sq < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};