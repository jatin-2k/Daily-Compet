class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> score(n+1);
        int cur = 0, mx = 0;
        for(int i=0; i<=n; i++){
            score[i]+=cur;
            mx = max(mx,score[i]);
            if(i<n)cur+= nums[i] == 0;
        }
        cur = 0;
        for(int i=n-1; ~i; i--){
            cur+= nums[i] == 1;
            score[i]+=cur;
            mx = max(mx, score[i]);
        }
        vector<int> ans;
        for(int i=0; i<=n; i++){
            //cout<<score[i]<<" ";
            if(mx == score[i]) ans.push_back(i);
        }
        return ans;
    }
    
};