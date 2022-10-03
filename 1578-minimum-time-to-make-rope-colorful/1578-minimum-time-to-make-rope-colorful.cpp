class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int n = colors.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int curT = arr[i];
            char curC = colors[i];
            while(i+1<n and curC == colors[i+1]){
                i++;
                if(arr[i] > curT){
                    ans += curT;
                    curT = arr[i];
                }
                else ans += arr[i];
            }
        }
        return ans;
    }
};