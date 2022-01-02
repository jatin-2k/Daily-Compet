class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int> arr(60,0);
        int ans=0;
        for(int i=0; i<n; i++){
            time[i] %= 60;
            ans += arr[(60-time[i])%60];
            arr[time[i]]++;
        }
        return ans;
    }
};