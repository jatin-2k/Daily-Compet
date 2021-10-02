class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans;
        stack<long long> st;
        for(int i=n-1; i>=0; i--){
            if(st.empty()) ans.push_back(-1);
            else if(st.top() > arr[i]){
                ans.push_back(st.top());
            }
            else if(st.top() <= arr[i]){
                while(!st.empty() and st.top() <= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top());
                }
            }
            st.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};