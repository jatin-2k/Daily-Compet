class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        return a.second > b.second;
    }
};

class Solution
{
    public:
    vector<int> dis;
    vector<bool> visited;
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        if(dis.size()==0) {
            dis = vector<int>(V,INT_MAX);
            visited = vector<bool>(V,0);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> minH;
        minH.push({S,0});
        while(!minH.empty()){
            int cur = minH.top().first;
            int curDis = minH.top().second;
            minH.pop();
            visited[cur] =1;
            dis[cur] = min(dis[cur], curDis);
            for(auto j: adj[cur]){
                if(!visited[j[0]]){
                    minH.push({j[0], j[1]+curDis});
                }
            }
        }
        return dis;
    }
};