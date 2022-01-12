class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int curDay, int m, int k){
        int count = 0;
        int size = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] > curDay) size = 0;
            else size++;
            if(size == k){
                count++;
                size = 0;
            }
        }
        return count >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < m*k) return -1;
        int l = INT_MAX, r = INT_MIN;
        for(auto i: bloomDay){
            l = min(l,i);
            r = max(r,i);
        }
        while(l<r){
            int mid = (l+r)/2;
            if(isPossible(bloomDay, mid, m, k)) r = mid;
            else l = mid+1;
        }
        return l;
    }
};