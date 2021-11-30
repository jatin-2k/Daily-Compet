class Solution {
    vector<int> c;
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        c = vector<int>(10001);
        ans={0};
        for(int i=0; i<ans.size(); i++){
            for(auto j: adj[ans[i]]){
                if(c[j] == 0)ans.push_back(j);
                c[j]=1;
            }
        }
        return ans;
    }
};