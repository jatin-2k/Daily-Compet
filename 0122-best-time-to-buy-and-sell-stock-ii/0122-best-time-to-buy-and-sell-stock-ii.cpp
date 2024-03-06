class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<int> buy(n+1, INT_MIN), sell(n+1);
        buy[0] = -arr[0];
        for(int i=1; i<n; i++){
            buy[i] = max(buy[i-1], sell[i-1] - arr[i]);
            sell[i] = max(sell[i-1], buy[i]+arr[i]);
        }
        
        return sell[n-1];
    }
};