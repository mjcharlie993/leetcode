//Source : https://leetcode.com/problems/plus-one/
//Author : Mao Jiachen
//Data   : 2016/11/29

/***************************************************************************************
 *
 * Approach: Judge the Lowest Bit  
 *
 * Reverse traversal(low to high) the vector and judge every bit less than 9,
 * if the digit is less than 9, add 1 to this digit, and return result.
 * if the digit is 9, reset it to 0, and enter next bit traversal. 
 *
 * if the highest exist carry, add one extra bit and make it set 0, regard it as
 * the lowest bit. Than reset the highest bit to 1.
 ***************************************************************************************/
 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};
