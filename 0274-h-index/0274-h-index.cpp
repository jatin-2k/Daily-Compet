class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for(int i=n-1; ~i; i--){
            //cout<<arr[i]<<" , "<<n-i<<endl;
            if(arr[i] < n-i) return n-i-1;
        }
        return n;
    }
};