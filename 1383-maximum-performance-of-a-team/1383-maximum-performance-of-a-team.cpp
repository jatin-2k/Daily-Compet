
class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& as, vector<int>& ae, int k) {
        vector<vector<int>> arr;
        for(int i=0; i<n; i++) arr.push_back({ae[i], as[i]});
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> minH;
        long long int sum = 0;
        long long int ans = 0;
        for(int i=n-1; i>=0; i--){
            if(minH.size() >= k){
                sum -= minH.top();
                minH.pop();
            }
            
            sum += arr[i][1];
            minH.push(arr[i][1]);
            
            ans = max(ans, arr[i][0]*sum);
        }
        return ans%MOD;
    }
};