class Solution
{
    public:
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        vector<int> ind(V,0), ans;
        for(int i=0; i<V; i++){
            for(auto j: adj[i]){
                ind[j]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            int cur = q.front();
            ans.push_back(cur);
            for(auto j: adj[cur]){
                ind[j]--;
                if(ind[j]==0) q.push(j);
            }
            q.pop();
        }
        return ans;
    }
};
