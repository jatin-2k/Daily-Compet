class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int l=0, r = n-1, h = 0;
        while(l<r){
            if(h < min(arr[l], arr[r])){
                int overlap = h*(r-l-1);
                h = min(arr[l], arr[r]);
                ans += h*(r-l-1) - overlap;
                //cout<<"h:"<<h<<" adding:"<<h*(r-l-1)-overlap<<" l:"<<l<<" r:"<<r<<endl;
            }
            if(arr[r] < arr[l]){
                r--;
                if(l<r) ans -= min(h, arr[r]);
                //cout<<"moving r:"<<r<<" reducing"<<min(arr[r],h)<<endl;
            }
            else {
                l++;
                if(l<r) ans -= min(h, arr[l]);
                //cout<<"moving l:"<<l<<" reducing"<<min(arr[l],h)<<endl;
            }
        }
        return ans;
    }
};