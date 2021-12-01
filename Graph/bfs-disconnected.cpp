class Solution {
    vector<int> c;
  public:
  vector<bool> visited;
  vector<int> ans;
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        visited = vector<bool>(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bfs(adj, i);
            }
        }
        return ans;
    }
    
    void bfs(vector<int> adj[], int i){
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty()){
            int cur = q.front();
            for(auto j: adj[cur]){
                if(!visited[j]){
                    visited[j]=1;
                    q.push(j);
                }
            }
            ans.push_back(cur);
            q.pop();
        }
    }
};