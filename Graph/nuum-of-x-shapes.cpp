class Solution
{
    public:
    int r,c;
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        r = grid.size();
        c = grid[0].size();
        int count=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 'X'){
                    bfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
    
    void bfs(int i, int j, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 'O';
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            if(check(i-1,j  ,grid)) q.push({i-1,j  });
            if(check(i  ,j-1,grid)) q.push({i  ,j-1});
            if(check(i+1,j  ,grid)) q.push({i+1,j  });
            if(check(i  ,j+1,grid)) q.push({i  ,j+1});
            q.pop();
        }
    }
    
    bool check(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]!='X') return false;
        if(grid[i][j]=='X'){
            grid[i][j] = 'O';
            return true;
        }
    }
};