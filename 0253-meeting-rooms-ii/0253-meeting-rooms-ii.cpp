typedef pair<int,int> pi;
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
        priority_queue<pi, vector<pi>, greater<pi>> minH;
        for(int i=0; i<n; i++){
            int start = arr[i][0]; int end = arr[i][1];
            while(!minH.empty() && minH.top().first <= start){
                minH.pop();
            }
            minH.push({end, minH.size() + 1});
            ans = max(ans, (int)minH.size());
        }
        return ans;
    }
};