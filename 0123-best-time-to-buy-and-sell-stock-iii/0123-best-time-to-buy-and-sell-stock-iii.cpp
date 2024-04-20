class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int t1Cost = INT_MIN, 
        t2Cost = INT_MIN;
    int t1Profit = 0,
        t2Profit = 0;

    for (int price : prices) {
        // the maximum profit if only one transaction is allowed
        t1Cost = max(t1Cost, -price);
        t1Profit = max(t1Profit, price + t1Cost);
        // re-invest the gained profit in the second transaction
        t2Cost = max(t2Cost, -price + t1Profit);
        t2Profit = max(t2Profit, price + t2Cost);
    }

    return t2Profit;
  }
};