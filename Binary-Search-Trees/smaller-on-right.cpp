class Solution {
public:
int max = 0;
    int countSmaller(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            
            auto it=s.lower_bound(nums[i]);
            int t=distance(s.begin(),(it));  
            if(t>max) max = t;
            s.insert(nums[i]);
        }
        return max;       
    }
};