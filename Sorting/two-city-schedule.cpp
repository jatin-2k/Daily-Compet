class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), a = 0, b = 0;
        sort(costs.begin(), costs.end(), [](vector<int>& v1, vector<int>& v2){
            return v1[1] - v1[0] > v2[1] - v2[0];
        });
        for(int i=0; i<n; i++){
            b += i>=n/2 ?costs[i][1] : 0;
            a += i<n/2 ? costs[i][0] : 0;
        }
        //cout<<a<<" "<<b;
        return a+b;
    }
};