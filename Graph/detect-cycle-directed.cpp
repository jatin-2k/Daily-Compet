class Solution {
  public:
    vector<bool> isDead;
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        isDead = vector<bool>(V,0);
        for(int i=0; i<V; i++){
            if(!isDead[i]){
                vector<bool> visited(V,0);
                if(dfs(adj,i,visited)) return true;
                else isDead[i] = true;
            }
        }
        return false;
    }
    
    bool dfs(vector<int> adj[], int i, vector<bool> &visited){
        visited[i] = 1;
        if(isDead[i]) return false;
        else{
            for(auto j: adj[i]){
                if(visited[j]) return true;
                if(isDead[j]) continue;
                if(dfs(adj,j,visited)) return true;
                else isDead[j] = true;
            }
            visited[i] = 0;
            return false;
        }
    }
};