class Solution {
public:
    int maxArea(vector<int>& arr) {
        int ans = 0;
        int r = arr.size()-1, l = 0;
        while(l<r){
            ans = max(ans, min(arr[r], arr[l])*(r-l));
            if(arr[r] < arr[l]) r--;
            else l++;
        }
        return ans;
    }
};