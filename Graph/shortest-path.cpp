class Solution {
public:
    vector<int> shortestPathLength(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> dis(graph.size());
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int cur = q.front();
            for(auto j: graph[cur]){
                if(!visited[j]){
                    dis[j] = dis[cur]+1;
                    visited[j] =1;
                    q.push(j);
                }
            }
            q.pop();
        }
        return dis;
    }
};