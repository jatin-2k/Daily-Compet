class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), ans = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                auto it = mp.find(0-nums3[i]-nums4[j]);
                if(it != mp.end()){
                    ans+= it->second;
                }
            }
        }
        return ans;
    }
};