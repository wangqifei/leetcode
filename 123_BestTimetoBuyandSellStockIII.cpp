// 123 Best Time to Buy and Sell Stock III
// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    //o(n) time, o(n) space
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int len = prices.size();
        vector<int> maxProfitSt(len, 0);
        vector<int> maxProfitEd(len, 0);
        int buyPrice = prices[0];
        for(int i = 1; i < len; ++i) {
            maxProfitSt[i] = max(maxProfitSt[i-1], prices[i]-buyPrice);
            buyPrice = min(buyPrice, prices[i]);
        }
        int sellPrice = prices.back();
        for(int i = len-2; i >= 0; --i) {
            maxProfitEd[i] = max(maxProfitEd[i+1], sellPrice - prices[i]);
            sellPrice = max(sellPrice, prices[i]);
        }
        int res = INT_MIN;
        for(int i = 0; i < len; ++i) {
            res = max(res, maxProfitSt[i]+maxProfitEd[i]);
        }
        return res;
    }
};