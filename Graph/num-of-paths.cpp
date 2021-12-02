class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        if(source == destination) return 1;
        int cnt = 0;
        for(auto i: adj[source]){
            cnt+= countPaths(V, adj, i, destination);
        }
        return cnt;
    }
};