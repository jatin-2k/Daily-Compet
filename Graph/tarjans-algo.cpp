class Solution
{
	public:
	
	void findSCCUtil(int u, int discoveryTime[], int lowTime[], stack<int>& s, bool inStack[], vector<int> adj[], int &time, vector<vector<int>> &ans) {

        discoveryTime[u] = lowTime[u] = time++;
        s.push(u);
        inStack[u] = true;
    
        vector<int> :: iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {
    
            int v = *itr;
    
            if (discoveryTime[v] == -1) {
                findSCCUtil(v, discoveryTime, lowTime, s, inStack, adj, time, ans);
                lowTime[u] = min(lowTime[u], lowTime[v]);
            }
            else if (inStack[v] == true) {
                lowTime[u] = min(lowTime[u], discoveryTime[v]);
            }
        }
        
        vector<int> temp;
        if (lowTime[u] == discoveryTime[u]) {
            int curr;
            while (s.top() != u) {
                curr = s.top();
                temp.push_back(curr);
                s.pop();
                inStack[curr] = false;
            }
            curr = s.top();
            temp.push_back(curr);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            s.pop();
            inStack[curr] = false;
        }
    }
    
    static bool cmp(vector<int> &i1, vector<int> &i2)
    {
        return (i1[0] < i2[0]);
    }
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code 
        int discoveryTime[V];
        int lowTime[V];
        bool inStack[V];
        vector<vector<int>> ans;
        memset(discoveryTime, -1, sizeof(discoveryTime));
        memset(lowTime, -1, sizeof(lowTime));
        memset(inStack, false, sizeof(inStack));
    
        stack<int> s;
    
        int time = 0;
    
        for (int i = 0; i < V; ++i) {
            if (discoveryTime[i] == -1) {
                findSCCUtil(i, discoveryTime, lowTime, s, inStack, adj, time, ans);
               
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};