struct Edge{
    int a,b,weight;
    Edge(int from, int to, int w){
        a = from; b = to; weight = w;
    }
};

class Compare
{
    public:
    bool operator() (Edge a, Edge b)
    {
        return a.weight > b.weight;
    }
};

class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<Edge , vector<Edge>, Compare> minH; 
        map<int,bool> isTaken;
        int taken = 0;
        int ans =0;
        isTaken[0] = 1;
        for(auto j: adj[0]){
            minH.push(Edge(0,j[0],j[1]));
        }
        while(taken!=V-1 && !minH.empty()){
            Edge cur = minH.top();
            minH.pop();
            if(!isTaken[cur.b]){
                isTaken[cur.b] = 1;
                for(auto j: adj[cur.b]){
                    if(!isTaken[j[0]]){
                        minH.push(Edge(cur.b,j[0],j[1]));
                    }
                }
                ans += cur.weight;
                taken++;
            }
        }
        return ans;
    }
        
};   