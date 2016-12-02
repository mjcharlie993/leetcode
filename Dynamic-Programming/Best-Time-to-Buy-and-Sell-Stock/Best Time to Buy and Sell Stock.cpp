//Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//Author : Mao Jiachen
//Date   : 2016/11/30

/***************************************************************************************
 *
 * Approach: One Pass
 * Algorithm: Say the given array is [7,1,5,3,6,4].If we plot the numbers of the given 
 * array on a graph, we get:
 * 8
 * 7  *
 * 6                                  *
 * 5                  *
 * 4                                          *
 * 3                          *
 * 2       
 * 1          * 
 * 0          
 *    1       2       3       4       5       6       7
 * 
 * The points of interest are the peaks and valleys in the given graph.
 * We need to find the largest peak following the smallest  valley.
 * We can maintain two variables-minprice(price) and maxprofit(max) corresponding to the smallest 
 * valley and maximum profit(maximun difference between selling price and minprice) 
 * obtained so far respectively.
 * 
 **************************************************************************************/
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int minprice = prices[0];
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
            }
        return maxprofit;
    }
};
