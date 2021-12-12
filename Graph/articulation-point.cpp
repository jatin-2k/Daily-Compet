class Solution {
  public:
    vector<bool> visited, ap;
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> low(V,INT_MAX), disc(V, INT_MAX), parent(V,-1);
        visited = vector<bool>(V,0);
        ap = vector<bool>(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                apUtil(i, adj, V, parent, low, disc);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(ap[i]){
                ans.push_back(i);
            } 
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
    
    void apUtil(int u, vector<int> adj[], int V, vector<int>& parent, vector<int>& low, vector<int>& disc ){
        static int t = 0;
        int children = 0;
        visited[u] = 1;
        disc[u] = low[u] = ++t;
        for(auto v: adj[u]){
            if(!visited[v]){
                children++;
                parent[v] = u;
                
                apUtil(v, adj, V, parent, low, disc);
                low[u] = min(low[u], low[v]);
                
                if (parent[u] == -1 && children > 1) 
                    ap[u] = true;   //means its root with multi children
                if (parent[u] != -1 && low[v] >= disc[u]) 
                    ap[u] = true;   //if child can not reach ancestors
            }
            else if (v != parent[u]) 
                low[u] = min(low[u], disc[v]);
        }
    }
};