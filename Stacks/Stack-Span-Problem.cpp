class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int a[], int n)
    {
       // Your code here
       stack<pair<int,int>> st;
       vector<int> ans;
       for(int i=0; i<n; i++){
           if(st.empty()) {
               ans.push_back(1);
           }
           
           else if(st.top().first > a[i]){
                   ans.push_back(1);
           }
           
           else if(st.top().first <= a[i]){
               while(!st.empty() and st.top().first <= a[i]){
                   st.pop();
               }
               if(st.empty()) ans.push_back(i+1);
               else ans.push_back(i - st.top().second);
           }
           st.push(make_pair(a[i],i));
       }
       return ans;
    }
};