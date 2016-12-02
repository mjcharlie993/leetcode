//Source : https://leetcode.com/articles/best-time-buy-and-sell-stock-ii/
//Author : Mao Jiachen
//Date   : 2016/11/30

/***************************************************************************************
 *
 * #1
 * Approach: Peak Valley Approach
 * Algorithm: Say the given array is: [7,1,5,3,6,4]. If we plot the numbers of the given
 * array on a graph, we get:
 *
 * 8
 * 7  *                             p(j)
 * 6                p(i)      |       *         |
 * 5          |       *       | B               |
 * 4          |               |               * | C
 * 3          | A             *                 |
 * 2          |              v(j)               |
 * 1          *                                 |    
 * 0         v(i)  
 *    1       2       3       4       5       6       7 
 *
 * If we analyze the graph, we notice that the points of interset are the consecutive 
 * valley and peak
 * Mathematically speaking:    TotalProfit = sum(i) (height(peak(i) - height(valley(i)))
 * The key point is we need to consider every peak immediately following a valley to 
 * maximize the profit. In case we skip one of the peaks(trying to obtain more profit),
 * we will end up losing the profit over one of the transactions leading to an overall 
 * lesser profit.
 * For example, in the above case, if we skip peak(i) and valley(j) trying to obtail 
 * more profit with more difference in heights, the net profit obtained will always be
 * lesser than the one obtained by including them, Since C will always be lesser than A+B.
 *
 * #2
 * Approach: Simple One Plus
 * Algorithm: This solution follows the logic used in Approach 1 itself, but with only a 
 * slight variation. In this case, instead of looking for every peak following a valley,
 * we can simply go on crawling over the slope and keep on adding the profit obtained from
 * every consecutive transaction.
 * In the end, we will be using the peaks and valleys effectively, but we need not track
 * the costs corresponding to the peaks and valleys along with the maximum profit, but we
 * can directly keep on adding the difference between the consecutive numbers of the array
 * if the second number is larger than the first one, and at the total sum we obtain will 
 * be the maximum profit. 
 * This approach will simplify the solutin.This can be made clearer by taking this example
 * [1,7,2,3,6,7,6,7]
 * The graph corresponding to this array is:
 * 
 * 8
 * 7          *                       | C     *          |    *
 * 6                          |       *               *  |
 * 5                          | B                        | D
 * 4                          |                          |
 * 3                  | A     *                          |
 * 2                  *                           
 * 1  *                                         
 * 0        
 *    1       2       3       4       5       6       7       8
 *
 * From the above graph, we can observe that the sum A+B+C is equal to the difference D
 * corresponding to the difference between the heights of the consecutive peak and valley.
 *
 ****************************************************************************************/
 
 //#1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};

 //#2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
            return maxprofit;
    }
};
        
