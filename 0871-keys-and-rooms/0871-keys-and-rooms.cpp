class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        queue<int> q;
        int cnt = 0;
        q.push(0);
        while(!q.empty()){
            int room = q.front(); q.pop();
            if(visited[room]) continue;
            cnt++;
            visited[room] = true;
            vector<int> keys = rooms[room];
            for(auto x: keys) {
                if(!visited[x]) q.push(x);
            }
        }
        cout<<cnt<<endl;
        return cnt == rooms.size();
    }
};