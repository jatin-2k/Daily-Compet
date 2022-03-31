class Solution {
public:
    bool canSplit(vector<int>& nums, int x, long long mx){
        int cur = 0;
        for(auto num: nums){
            if(num > mx) return false;
            if(num+cur > mx){ 
                x--;
                cur=num;
                if(x<0) return false;
            }
            else cur+=num;
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long l =0, r=0;
        for(int num: nums){
            l = max(l, (long long)num);
            r += num;
        }
        while(l<r){
            long long mid = l+(r-l)/2;
            //cout<<mid<<" ";
            if(canSplit(nums,m-1,mid)) r = mid;
            else l = mid+1;
        }
        //cout<<endl;
        return l;
    }
};