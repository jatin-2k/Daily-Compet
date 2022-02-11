class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(), cur=0, ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0; i<n; i++){
            cur+=arr[i];
            if(mp.find(cur-k) != mp.end()) ans+=mp[cur-k];
            mp[cur]++;
        }
        return ans;
    }
};