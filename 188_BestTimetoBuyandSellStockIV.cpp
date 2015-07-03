// 188 Best Time to Buy and Sell Stock IV
// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Credits:
// Special thanks to @Freezen for adding this problem and creating all test cases.

// Hide Tags Dynamic Programming


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len<2) return 0;
        int res = 0;
        if(len/2 > k) {
            for(int i = 1; i < len; ++i) {
                res += max(prices[i]-prices[i-1],0);
            }
            return res;
        }
        vector<int> rele(len+1,0);
        vector<int> hold(len+1, INT_MIN);
        for(int i = 0; i < len; ++i) {
            for(int j = k; j > 0; --j) {
                rele[j] = max(rele[j], hold[j]+prices[i]);
                hold[j] = max(hold[j], rele[j-1]-prices[i]);
            }
        }
        return rele[k];
    }
};