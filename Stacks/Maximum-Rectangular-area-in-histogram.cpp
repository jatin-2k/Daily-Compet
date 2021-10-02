class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> l, r;
        long long max =0,cur = 0;
        l = ToLeft(arr,n);
        r = ToRight(arr,n);
        
        for(int i=0; i<n; i++){
            cur = arr[i]*(r[i]-l[i]-1);
            if(cur>max) max = cur;
        }
        return max;
    }
    
    vector<long long> ToLeft(long long arr[], int n){
        stack<pair<long long,int>> st;
        vector<long long> ans;
        for(int i=0; i<n; i++){
            if(st.empty()) ans.push_back(-1);
            else if(st.top().first < arr[i]){
                ans.push_back(st.top().second);
            }
            else if(st.top().first >= arr[i]){
                while(!st.empty() and st.top().first >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top().second);
                }
            }
            st.push(make_pair(arr[i],i));
        }
        return ans;
    } 
    
    vector<long long> ToRight(long long arr[], int n){
        stack<pair<long long,int>> st;
        vector<long long> ans;
        for(int i=n-1; i>=0; i--){
            if(st.empty()) ans.push_back(n);
            else if(st.top().first < arr[i]){
                ans.push_back(st.top().second);
            }
            else if(st.top().first >= arr[i]){
                while(!st.empty() and st.top().first >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(n);
                }
                else{
                    ans.push_back(st.top().second);
                }
            }
            st.push(make_pair(arr[i],i));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    } 
};

//  6  2 5 4 5  1  6
// -1 -1 1 1 3 -1  5
//  1  5 3 5 5  n  n
//  6 10 5 12 1 7. 6