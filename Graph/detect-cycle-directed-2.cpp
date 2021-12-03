class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> ind(V,0), ans;
        queue<int> q;
        for(int i=0; i<V; i++){
            for(auto j : adj[i]){
                ind[j]++;
            }
        }
        for(int i=0; i<V; i++){
            if(ind[i]==0){ 
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            count++;
            for(auto j: adj[cur]){
                ind[j]--;
                if(ind[j]==0) q.push(j);
            }
        }
        if(count!=V) return 1;
        return 0;
    }
};