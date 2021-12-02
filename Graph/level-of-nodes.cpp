class Solution
{
    public:
    vector<bool> visited;
    //Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        visited = vector<bool>(V,0);
        queue<int> q;
        q.push(0);
        visited[0]=1;
        int lv=0;
        while(!q.empty()){
            queue<int> temp;
            while(!q.empty()){
                int cur = q.front();
                if(cur==X) return lv;
                temp.push(cur);
                q.pop();
            }
            while(!temp.empty()){
                int cur = temp.front();
                for(auto i: adj[cur]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] =1;
                    }
                }
                temp.pop();
            }
            lv++;
        }
        return -1;
    }
};