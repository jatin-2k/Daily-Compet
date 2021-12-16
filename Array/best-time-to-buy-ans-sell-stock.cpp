class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int n = prices.size();
        vector<int> l = ls(prices,n); 
        vector<int> r = rs(prices,n); 
        for(int i=0; i<n;i++){
            maxi = max(maxi, r[i]-l[i]);
        }
        return maxi;
    }
    
    vector<int> ls(vector<int>& prices, int n){
        vector<int> ans = {prices[0]};
        int min = prices[0];
        for(int i=1; i<n; i++){
            if(min > prices[i]){
                min = prices[i];
            }
            ans.push_back(min);
        }
        return ans;
    }
    vector<int> rs(vector<int>& prices, int n){
        vector<int> ans = {};
        int max = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(max < prices[i]){
                max = prices[i];
            }
            ans.push_back(max);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};