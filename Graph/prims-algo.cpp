class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,INT_MAX);
        vector<bool> mSet(V); 
        key[0]=0;
        int res=0; 
        for (int count = 0; count < V ; count++) 
        { 
            int u = -1; 
            
            //pick the minimum weight vertex that is not yet picked
            for(int i=0;i<V;i++){
                if(!mSet[i]&&(u==-1||key[i]<key[u])){
                    u=i;
                }
            }
            
            //add that vertex to min Span tree
            mSet[u] = true; 
            res+=key[u];
            
            //take edges from this vertex into consideration
            //to update weights of the nodes
            for (auto v: adj[u]){
                if (mSet[v[0]] == false){
                    key[v[0]] = min(key[v[0]],v[1]);
                }
            }
        } 
        return res;
    }
};

//{0,1 - 5}, {0,2 - 8}, {1,3 - 20}, {1,2 - 10}, {2,3 - 15}

//mset = {F,F,F,F}
//key. = {0,-,-,-}
//count=0; u=-1 -> 0;

//mset = {T,F,F,F}
//key. = {0,5,8,-}
//count=1; u=1;

//mset = {T,T,F,F}
//key. = {0,5,8,20}
//count=2; u=2;

//mset = {T,T,T,F}
//key. = {0,5,8,15}
//count=3; u=3;

//mset = {T,T,T,T}
//key. = {0,5,8,15}    