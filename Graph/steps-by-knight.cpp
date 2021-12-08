class Solution 
{
    public:
    vector<vector<int>> visited;
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&start,vector<int>&end,int N)
    {
        //1 based indexing remember
        visited = vector<vector<int>>(N+1, vector<int>(N+1,-1));
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = 0;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            if(i == end[0] && j == end[1]){
                //cout<<"Wow";
                return visited[i][j];
            }
            if(check(i-2,j-1,N, visited[i][j])) q.push({i-2,j-1});
            if(check(i-2,j+1,N, visited[i][j])) q.push({i-2,j+1});
            if(check(i+2,j-1,N, visited[i][j])) q.push({i+2,j-1});
            if(check(i+2,j+1,N, visited[i][j])) q.push({i+2,j+1});
            if(check(i-1,j-2,N, visited[i][j])) q.push({i-1,j-2});
            if(check(i-1,j+2,N, visited[i][j])) q.push({i-1,j+2});
            if(check(i+1,j-2,N, visited[i][j])) q.push({i+1,j-2});
            if(check(i+1,j+2,N, visited[i][j])) q.push({i+1,j+2});
            q.pop();
        }
        return visited[end[0]][end[1]];
    }
    
    bool check(int i, int j, int n, int par){
        if(i<=0 || i>n || j<=0 || j>n || visited[i][j]!=-1) return false;
        else{
            visited[i][j] = par+1;
            return true;
        }
    }
};