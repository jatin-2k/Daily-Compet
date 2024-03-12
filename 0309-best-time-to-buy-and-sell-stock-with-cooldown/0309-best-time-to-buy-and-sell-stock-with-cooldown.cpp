class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        vector<int> buy(n+1, INT_MIN), sell(n+1);
        buy[0] = -prices[0]; buy[1] = max(buy[0],-prices[1]);
        sell[1] = max(0,buy[0] + prices[1]);
        for(int i=2; i<n; i++){
            buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
            sell[i] = max(sell[i-1], buy[i] + prices[i]);
        }
        return sell[n-1];
    }
};