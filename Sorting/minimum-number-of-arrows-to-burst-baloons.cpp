class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 0, end = INT_MAX;
        bool isDone = false;
        for(int i=0; i<points.size(); i++){
            if(points[i][0] > end){
                count++; end = points[i][1];
            }
            else{
                end = min(end, points[i][1]);
            }
        }
        return count + !points.empty();
    }
};