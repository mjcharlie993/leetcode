//Source : https://leetcode.com/problems/valid-perfect-square/
//Author : Mao Jiachen
//Date   : 2017/06/08

/****************************************************************************************
 *
 ***************************************************************************************/

// #1
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        long x = num / 2, t = x * x;
        while (t > num) {
            x /= 2;
            t = x * x;
        }
        for (int i = x; i != x * 2; i++) 
            if (i * i == num)
                return true;
        return false;
    }
};

// #2
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= num / i; i++) 
            if (i * i == num)
                return true;
        return false;
    }
};

// #3
class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long t = mid * mid;
            if (t == num)
                return true;
            else if (t < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

// #4
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};

// #5
class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) 
            x = (x + num / x) / 2;
        return x * x == num;
    }
};