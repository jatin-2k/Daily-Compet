class Solution
{
    public:
    vector<bool> visited;
    stack<int> s;
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        visited = vector<bool>(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topo(i,adj);
            }
        }
        vector<int> tra[V];
        for(int i=0; i<V; i++){
            for(auto j: adj[i]){
                tra[j].push_back(i);
            }
        }
        visited = vector<bool>(V,0);
        vector<vector<int>> ans;
        while(!s.empty()){
            vector<int> temp;
            if(!visited[s.top()]){
                dfs(s.top(), tra, temp);
                ans.push_back(temp);
            }
            s.pop();
        }
        return ans.size();
    }
    
    void topo(int i,vector<int> adj[]){
        visited[i] =1;
        for(auto j: adj[i]){
            if(!visited[j]){
                topo(j,adj);
            }
        }
        s.push(i);
    }
    
    void dfs(int i,vector<int> adj[], vector<int>& ans){
        visited[i] = 1;
        for(auto j: adj[i]){
            if(!visited[j]){
                topo(j,adj);
            }
        }
        ans.push_back(i);
    }
};