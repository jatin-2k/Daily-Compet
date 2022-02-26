class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long count = 0, ans = LLONG_MAX, removed = 0, n = beans.size();
        for(long long i=0; i<n; i++){
            count+=beans[i];
        }
        sort(beans.begin(), beans.end());
        for(long long i=0; i<n; i++){
            ans = min(ans,count - beans[i]*(n-i) );
            removed += beans[i];
        }
        return ans;
    }
};