class Solution {
public:
    bool bs(vector<vector<int>>& m, int target, int l, int r){
        if(l <= r){
            int mid = (l+r)/2;
            int x = mid/m[0].size();
            int y = mid%m[0].size();
            if(m[x][y] == target) return true;
            if(m[x][y] < target) return bs(m, target, mid+1, r);
            if(m[x][y] > target) return bs(m, target, l, mid-1);
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& m, int t) {
        return bs(m, t, 0, m.size()*m[0].size()-1);
    }
};