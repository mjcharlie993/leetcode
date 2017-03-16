//Source : https://leetcode.com/problems/length-of-last-word/
//Author : Mao Jiachen
//Date   : 2017/03/16

/********************************************************************
 *
 * Algorithm: start at the last elem of the sentence.
 *
 *******************************************************************/

class solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0, n = s.size();
        while (s[n - 1] == ' ') n--;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ')
                cnt++;
            else
                break;
        }
        return cnt;
    }
}