class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        //using indegree based topo sort to get parents from leafs
        vector<int> topo = topoSort(adj,n);
        //if there was no edge than topo sorted list will be empty
        if(topo.size() == 0) return {0};
        //height from frist parent
        int first = getH(topo[0], adj, n);
        //height from another parent node as source
        int second = getH(topo[1], adj, n);
        
        if(first == second) return {topo[0],topo[1]};
        else return {topo[0]};
    }
    
    vector<int> topoSort(vector<int> adj[], int V){
        vector<int> inDeg(V,0);
        for(int i=0; i<V; i++){
            for(auto j: adj[i]){
                inDeg[i]++;
            }
        }
        queue<int> q;
        stack<int> s;
        for(int i=0; i<V; i++)
            if(inDeg[i]==1){
                inDeg[i] = 0;
                q.push(i);
            }
        
        while(!q.empty()){
            int cur = q.front();
            inDeg[cur] = 0;
            for(auto i: adj[cur]){
                inDeg[i]--;
                if(inDeg[i]==1){
                    inDeg[i] = 0;
                    q.push(i);
                }
            }
            s.push(cur);
            q.pop();
        }
        vector<int> topo;
        while(!s.empty()){
            topo.push_back(s.top());
            s.pop();
        }
        return topo;
    }
    
    int getH(int s, vector<int> adj[], int V){
        vector<int> h(V,INT_MAX);
        queue<int> q;
        q.push(s);
        h[s] = 0;
        int maxH = 0;
        while(!q.empty()){
            int cur = q.front();
            for(auto i: adj[cur]){
                if(h[i] == INT_MAX){
                    h[i] = h[cur]+1;
                    maxH = max(maxH, h[i]);
                    q.push(i);
                }
            }
            q.pop();
        }
        return maxH;
    }
};