class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), ans = 1, end = intervals[0][1], start = intervals[0][0];
        for(int i=1; i<n; i++){
            if(intervals[i][0] > start and intervals[i][1] > end){
                ans++;
            }
            if(intervals[i][1] > end){
                start = intervals[i][0];
                end = intervals[i][1];
            }
            
        }
        return ans;
    }
};