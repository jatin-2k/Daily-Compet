class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int l=0, r=arr[0].size()-1, b=arr.size()-1, t=0;
        vector<int> ans;
        while(l<=r && t<=b){
            for(int i=l; i<=r && t<=b; i++){
                ans.push_back(arr[t][i]);
            }
            t++;
            for(int i=t; i<=b && l<=r; i++){
                ans.push_back(arr[i][r]);
            }
            r--;
            for(int i=r; i>=l && t<=b; i--){
                ans.push_back(arr[b][i]);
            }
            b--;
            for(int i=b; i>=t && l<=r; i--){
                ans.push_back(arr[i][l]);
            }
            l++;
        }
        return ans;
    }
};