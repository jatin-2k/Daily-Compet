class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<pair<int,int>> s;
        vector<int> ans;
        for(int i=0; i<n; i++){
            int cur = price[i];
            int span = 1;
            while(!s.empty() && s.top().first <= cur) span+=s.top().second,s.pop();
            s.push({cur,span});
            ans.push_back(span);
        }
        return ans;
    }
};