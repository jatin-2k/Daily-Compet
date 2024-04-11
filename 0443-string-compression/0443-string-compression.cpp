class Solution {
public:
    int compress(vector<char>& arr) {
        int n=arr.size();
        vector<char> ans;
        int ansn = 0;
        for(int i=0; i<n; i++){
            if(i>0 && arr[i] == arr[i-1]) continue;
            int sz = 1;
            for(int j=i+1; j<n && arr[j]==arr[i]; j++) sz++;
            ans.push_back(arr[i]);
            ansn += sz;
            if(sz>1){
                vector<char> nums;
                while(sz){
                    nums.push_back((sz%10) + '0'); sz/=10;
                }
                ans.insert(ans.end(), nums.rbegin(), nums.rend());
            }
        }
        arr = ans;
        return ans.size();
    }
};