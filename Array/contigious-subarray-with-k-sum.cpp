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

public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                int sum = 0;
                for (int i = start; i < end; i++)
                    sum += nums[i];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}