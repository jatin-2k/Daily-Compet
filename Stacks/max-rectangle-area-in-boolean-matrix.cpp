class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> arr(r, vector<int>(c,0));
        vector<int> wave(c);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j]=='0') wave[j]=0;
                else wave[j]++;
                arr[i][j] = wave[j];
            }
        }
        int ans = 0;
        for(int i=0; i<r; i++){
            ans = max(ans,getMaxArea(arr[i],c));
        }
        return ans;
    }
    int getMaxArea(vector<int>& arr, int n)
    {
        vector<int> l,r;
        int max =0,cur = 0;
        l = ToLeft(arr,n);
        r = ToRight(arr,n);
        
        for(int i=0; i<n; i++){
            cur = arr[i]*(r[i]-l[i]-1);
            if(cur>max) max = cur;
        }
        return max;
    }
    
    vector<int> ToLeft(vector<int>& arr, int n){
        stack<int> s;
        vector<int> ans(n);
        for(int i=0; i<n ; i++){
            long long cur = arr[i];
            while(!s.empty() && arr[s.top()] >= cur) s.pop();
            ans[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }
        return ans;
    } 
    
    vector<int> ToRight(vector<int>& arr, int n){
        stack<int> s;
        vector<int> ans(n);
        for(int i=n-1; ~i ; i--){
            long long cur = arr[i];
            while(!s.empty() && arr[s.top()] >= cur) s.pop();
            ans[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }
        return ans;
    } 
};