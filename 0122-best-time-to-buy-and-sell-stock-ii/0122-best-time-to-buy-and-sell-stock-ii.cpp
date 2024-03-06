class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int j = i;
            while(j+1<n && arr[j+1] > arr[j]) j++;
            ans += arr[j] - arr[i];
            i=j;
        }
        return ans;
    }
};