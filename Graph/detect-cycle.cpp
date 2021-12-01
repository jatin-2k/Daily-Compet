class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(isGol(adj, V, -1, i, visited)) return 1;
            }
        }
        return false;
    }
    bool isGol(vector<int> adj[], int V, int parent, int i, vector<bool> &visited){
        visited[i] = 1;
        for(auto j: adj[i]){
            if(j==parent) continue;
            if(visited[j]) return true;
            if(isGol(adj, V, i, j, visited)) return true;
        }
        return false;
    }
};