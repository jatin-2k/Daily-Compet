class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, r=n-1;
        int piv = 0;
        if(nums[l] > nums[r]) while(l<r){
            int mid = (l+r)/2;
            if(mid != 0 and nums[mid-1] > nums[mid]){
                piv = mid; break;
            }
            if(mid != n-1 and nums[mid+1] < nums[mid]){
                piv = mid+1; break;
            }
            if(nums[mid] > nums[r]) l = mid+1;
            else r = mid-1;
        }
        l = 0; r = piv-1;
        while(l<=r){
            int mid = (l+r)/2;
            //cout<<nums[l]<<" "<<nums[mid]<<" "<<nums[r]<<endl;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        l = piv; r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};