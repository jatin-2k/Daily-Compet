class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = popped.size();
        int m = pushed.size();
        for(int i=0, j=0; i<n and j<=m; i++){
            while(st.empty() or j<m and st.top() != popped[i]){
                st.push(pushed[j]); j++;
            }
            //if(!st.empty()){
                if(st.top() == popped[i]) st.pop();
                else return false;
            //}
        }
        return true;
    }
};