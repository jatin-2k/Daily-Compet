class Solution
{
    public:
    vector<bool> visited;
    stack<int> ans;
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        visited = vector<bool>(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(adj, i);
            }
        }
        vector<int> res;
        while(!ans.empty()){
            res.push_back(ans.top());
            ans.pop();
        }
        return res;
    }
    
    void dfs(vector<int> adj[], int i){
        visited[i] = 1;
        for(auto j: adj[i]){
            if(!visited[j]){
                dfs(adj, j);
            }
        }
        ans.push(i);
    }
};