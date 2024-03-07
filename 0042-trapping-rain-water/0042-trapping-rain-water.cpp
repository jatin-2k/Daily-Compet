class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> nl = ngl(arr,n);
        vector<int> nr = ngr(arr,n);
        // for(int i=0; i<n; i++) cout<<nl[i]<<", ";
        // cout<<endl;
        for(int i=0; i<n; i++){
            if(nl[i] == -1 || nr[i] == n) continue;
            ans += min(arr[nl[i]], arr[nr[i]]) - arr[i];
        }
        return ans;
    }
    
    vector<int> ngl(vector<int> &arr, int &n){
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            if(st.empty() || arr[i] > arr[st.top()] ) st.push(i);
        }
        return ans;
    }
    
    vector<int> ngr(vector<int> &arr, int &n){
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            if(st.empty() || arr[i] > arr[st.top()] ) st.push(i);
        }
        return ans;
        //return {7,7,7,7,7,7,7,12,12,10,12,12};
    }
};