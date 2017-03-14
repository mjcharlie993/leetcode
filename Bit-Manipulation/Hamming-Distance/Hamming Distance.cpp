//Author : https://leetcode.com/problems/hamming-distance/
//Author : Mao Jiachen
//Date   : 2017/03/14

/********************************************************************
 *
 * Hamming Distance between two strings of equal length is the number
 * of positions at which the corresponding symbols are different. 
 * 
 *******************************************************************/

class solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, exc = x ^ y;
        for (int i = 0; i < 32; ++i) {
            res += (exc >> i) & 1;
        }
        return res;
    }
}