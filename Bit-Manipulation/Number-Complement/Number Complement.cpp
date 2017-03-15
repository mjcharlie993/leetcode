//Source : https://leetcode.com/problems/number-complement/
//Author : Mao Jiachen
//Date   : 2017/03/15

/********************************************************************
 *
 * Approach: Bit ~
 * Algorithm: The complement is to flip the bits of its binary
 * representation. 
 *
 *******************************************************************/

class solution {
public:
    int findComplement(int num) {
        int mask = 1, temp = num;
        while (temp) {
            temp >>= 1;
            mask <<= 1;
        }
        return num ^ (mask - 1);
    }
};