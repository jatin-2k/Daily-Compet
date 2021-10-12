class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> a, int n){
        // code here
        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++){
            int t;
            while(i<n-1 and a[i]>a[i+1]) i++;
            t = i;
            while(i<n-1 and a[i]<a[i+1]) i++;
            if(i<n and a[t]<a[i]){
                ans.push_back({t,i});
            }
        }
        
        return ans;
    }
};