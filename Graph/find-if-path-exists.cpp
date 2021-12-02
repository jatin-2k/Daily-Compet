class Solution
{
    public:
    vector<vector<bool>> visited;
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        pair<int,int> start, end;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) start = {i,j};
                if(grid[i][j]==2) end   = {i,j};
            }
        }
        queue<pair<int,int>> q;
        visited = vector<vector<bool>>(n, vector<bool>(n,0));
        q.push(start);
        while(!q.empty()){
            pair<int,int> cur = q.front();
            int i = cur.first, j = cur.second;
            if(cur == end) return true;
            if(isVP(i-1,j  ,n,grid)) q.push({i-1,j  });
            if(isVP(i  ,j-1,n,grid)) q.push({i  ,j-1});
            if(isVP(i+1,j  ,n,grid)) q.push({i+1,j  });
            if(isVP(i  ,j+1,n,grid)) q.push({i  ,j+1});
            visited[i][j] = 1;
            q.pop();
        }
        return false;
    }
    
    bool isVP(int i, int j, int n, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=n || !grid[i][j] || visited[i][j])
            return false;
        visited[i][j] = 1;
        return true;
    }
};