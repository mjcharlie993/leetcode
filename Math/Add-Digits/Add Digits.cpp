//Source : https://leetcode.com/problems/add-digits/
//Author : Mao Jiachen
//Data   : 2017/01/07

/****************************************************************************************
 * 
 * #1
 * Approach : Normal Solution
 * 
 * #2
 * Approach : Find the Regular Pattern 
 * 1-9   is 1-9, 
 * 10-18 is 1-9
 * 19-27 is 1-9
 * ... 
 * every 9 times is a cycle
 * 
 *
 ***************************************************************************************/

 //#1
class Solution {
public:
    int addDigits(int num) {
        while (num / 10 > 0) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

 //#2
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};