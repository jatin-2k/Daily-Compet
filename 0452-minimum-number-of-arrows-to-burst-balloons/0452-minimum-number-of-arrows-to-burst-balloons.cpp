class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int reach = points[0][1], cur = 0, ans = 0;
        for(auto v: points){
            if(v[0] > reach){
                ans++;
                reach = v[1];
            }
            reach = min(reach, v[1]);
        }
        return ++ans;
    }
};