//Source : https://leetcode.com/problems/teemo-attacking
//Author : Mao Jiachen
//Date   : 2016/03/14

/*******************************************************************
 *
 * Approach: Greedy Algorithm
 * Algorithm: ...
 *
 ******************************************************************/

class solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int res = 0, n = timeSeries.size();
        for (int i = 1; i < n; ++i) {
            int diff = timeSeries[i] - timeSeries[i - 1];
            res += (diff < duration) ? diff : duration;
        }
        return res + duration;
    }
};