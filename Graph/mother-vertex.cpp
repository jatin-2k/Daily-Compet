class Solution 
{
    public:
    vector<bool> visited;
    //Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int>adj[])
    {
        visited = vector<bool>(V,0);
        for(int i=0 ;i<V; i++){
            if(!visited[i]){
                int val = 0;
                dfs(i,adj,val);
                if(val==V) return i;
            }
        }
        return -1;
    }
    
    void dfs(int i, vector<int> adj[], int &val){
        visited[i] = 1;
        val++;
        for(auto j: adj[i]){
            if(!visited[j]){
                dfs(j,adj,val);
            }
        }
    }
};