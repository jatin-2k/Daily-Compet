class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort( nums.begin(), nums.end() );
        int n = nums.size();
        vector<vector<int>> ans;
        for(int l=n-1; l>=3; l--){
            for(int k=l-1; k>=2; k--){
                int myTarget = target - nums[l] - nums[k];
                int i=0;
                int j=k-1;
                while(i<j){
                    long long sum = 0;
                    sum +=nums[i];
                    sum +=nums[j];
                    if(sum==myTarget){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(i+1<j and nums[i+1]==nums[i]) i++;
                        while(i<j-1 and nums[j-1]==nums[j]) j--;
                    }
                    if(sum<myTarget){
                        i++;
                    }
                    else{
                        j--;  
                    }
                }
                while(2<=k-1 and nums[k-1]==nums[k]) k--;
            }
            while(3<=l-1 and nums[l-1]==nums[l]) l--;
        }
        //Because of all while loops we dont need this...........
        //set<vector<int>> s;
        //for( unsigned i = 0; i < ans.size(); ++i ) s.insert( ans[i] );
        //ans.assign( s.begin(), s.end() );
        return ans;
    }
};