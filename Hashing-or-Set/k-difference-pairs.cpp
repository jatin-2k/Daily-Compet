class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        set<pair<int,int>> st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[i]-nums[j])==k){
                    if(st.find({nums[i],nums[j]}) == st.end() and st.find({nums[j],nums[i]}) == st.end()){
                        ans++;
                    }
                    st.insert({nums[i],nums[j]});
                    st.insert({nums[j],nums[i]});
                }
            }
        }
        return ans;
    }
}; 