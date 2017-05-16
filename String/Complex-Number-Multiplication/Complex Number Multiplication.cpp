//Source : https://leetcode.com/problems/complex-number-multiplication/
//Author : Mao Jiachen
//Date   : 2017/05/16

/*************************************************************************
 *
 * stringstream is used to reset string to int and use int number to calc
 * 
 * stringstream 
 * website: http://blog.csdn.net/xw20084898/article/details/21939811
 *************************************************************************/

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, rb, ia, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra * rb - ia * ib << '+' << ra * ib + rb * ia << 'i';
        return ans.str();
    }
};
