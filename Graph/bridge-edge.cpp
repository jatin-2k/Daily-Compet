class Solution
{
    public:
    vector<bool> visited;
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        visited = vector<bool>(V,0);
        
        dfs(c, adj, c, d);
        
        if(!visited[d]) return true;
        return false;
    }
    void dfs(int i, vector<int> adj[], int c, int d){
        visited[i] = 1;
        for(auto j: adj[i]){
            if((i==c && j==d) || (i==d && j==c)) continue;
            if(!visited[j]){
                dfs(j, adj, c, d);
            }
        }
    }
};