class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(10001,0);
        int n = nums.size();
        for(auto i: nums){
            arr[i]+=i;
        }
        arr[1] = max(arr[0],arr[1]);
        for(int i=2; i<10001; i++){
            arr[i] = max(arr[i-1], arr[i-2]+arr[i]);
        }
        return arr[10000];
    }
};