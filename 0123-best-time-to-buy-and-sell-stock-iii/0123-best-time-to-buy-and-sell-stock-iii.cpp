class Solution {
public:
    int n;
    vector<int> prices;
    
    vector<int> profit;
    
    
    void solve(int numTran){
        if(numTran <= 0) return;
        profit[0] = profit[0] - prices[0];
        for(int i=1; i<n; i++){
            profit[i] = max(profit[i-1], profit[i]-prices[i]);
        }
        profit[0] = profit[0] + prices[0];
        for(int i=1; i<n; i++){
            profit[i] = max(profit[i-1], profit[i]+prices[i]);
        }
        solve(numTran-1);
    }
    int maxProfit(vector<int>& prices) {
        this->n = prices.size();
        this->prices = prices;
        this->profit = vector<int>(prices.size(), 0);
        solve(2);
        return profit[n-1];
    }
};

//  3  3  5  0  0  3  1  4

// -3 -3 -3  0  0  0. 0. 0
//  0. 0  2. 2  2. 3  3. 4
// -3 -3 -3  2. 2  2  2  2
//  0  0. 2  2  2  5  5  6
// -3 -3 -3  2  2  2  4  4
//  0. 0. 2  2. 2  5  5. 8

    