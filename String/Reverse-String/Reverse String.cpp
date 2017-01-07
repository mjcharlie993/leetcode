//Source : https://leetcode.com/problems/reverse-string/
//Author : Mao Jiachen
//Data   : 2016/01/07

class Solution {
public:
    string reverseString(string s) {
        int n = s.size() - 1;
        for (int i = 0; i <= n / 2; i++)
            swap(s[i], s[n-i]);
        return s;
    }
};