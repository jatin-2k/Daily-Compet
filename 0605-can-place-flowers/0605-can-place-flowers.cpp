class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int t) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0 && (i+1>=n || arr[i+1] == 0)){
                ans++; i++;
            }
            else if(arr[i] == 1) i++;
        }
        return ans >= t;
    }
};