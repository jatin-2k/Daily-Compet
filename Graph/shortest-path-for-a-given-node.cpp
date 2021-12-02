class Solution
{
    public:
    //Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        if(X>=V) return -1;
        vector<bool> visited(V, false);
        vector<int> dis(V,-1);
        queue<int> q;
        q.push(0);
        visited[0]=1;
        dis[0]=0;
        while(!q.empty()){
            int cur = q.front();
            for(auto j: adj[cur]){
                if(!visited[j]){
                    dis[j] = dis[cur]+1;
                    visited[j] =1;
                    q.push(j);
                }
            }
            q.pop();
        }
        return dis[X];
    }
};
