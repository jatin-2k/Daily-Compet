class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans = vector<int>(n,-1);
        int maxIndex = std::distance(nums.begin(), std::max_element(nums.begin(), nums.end()));
        //cout<<"mxIdx: "<<maxIndex<<endl;
        for(int i=0,j=maxIndex; i<n; i++){
            int cur = nums[j];
            while(!s.empty() && nums[s.top()] <= cur) s.pop();
            ans[j] = (s.empty()) ? -1 : nums[s.top()];
            s.push(j);
            j = (j!=0) ? --j : n-1;
        }
        return ans;
    }
};