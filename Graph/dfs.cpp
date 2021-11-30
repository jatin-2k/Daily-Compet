class Solution {
  public:
    vector<int> c;
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        c = vector<int>(10001);
        c[0]=1;
        vector<int> ans = {0};
        dfs(adj, 0, ans, V);
        return ans;
    }
    
    void dfs(vector<int> adj[], int i, vector<int> &ans, int v){
        if(i>=v) return;
        for(auto j : adj[i]){
            if(c[j]==0){
                ans.push_back(j);
                c[j]=1;
                dfs(adj, j, ans, v);
            }
        }
    }
};