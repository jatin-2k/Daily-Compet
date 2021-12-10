class Solution
{
    public:
    vector<int> dis;
    vector<bool> visited;
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        dis = vector<int>(V,INT_MAX);
        visited = vector<bool>(V,0);
        int count = 0;
        dis[S] = 0;
        while(count != V){
            int cur = -1;
            for(int i=0; i<V; i++){
                if(!visited[i]){
                    if(cur == -1 || dis[i] < dis[cur]) cur = i;
                }
            }
            visited[cur] = 1;
            for(auto j: adj[cur]){
                dis[j[0]] = min(dis[j[0]], dis[cur] + j[1]);
            }
            count++;
        }
        return dis;
    }
};