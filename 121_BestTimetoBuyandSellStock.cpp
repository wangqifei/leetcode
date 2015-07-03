// 121 Best Time to Buy and Sell Stock Total Accepted: 52453 Total Submissions: 160729 My Submissions Question Solution 
// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int minPrice = prices[0];
        int maxProfit = INT_MIN;
        for(int i = 0; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};