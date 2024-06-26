class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<n; i++){
            while(!dq.empty() && arr[i] >= arr[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
                if(i-dq.front() == k-1) dq.pop_front();
            }
        }
        return ans;
    }
};