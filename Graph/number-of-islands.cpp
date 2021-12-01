class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                   // cout<<i<<" "<<j<<endl;
                    bfs(grid, i,j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            
            grid[x][y] = '0';
            if(check(grid,x-1,y-1)) q.push({x-1,y-1});
            if(check(grid,x-1,y)) q.push(  {x-1,y  });
            if(check(grid,x-1,y+1)) q.push({x-1,y+1});
            if(check(grid,x,y-1)) q.push(  {x  ,y-1});
            if(check(grid,x,y+1)) q.push(  {x  ,y+1});
            if(check(grid,x+1,y-1)) q.push({x+1,y-1});
            if(check(grid,x+1,y)) q.push(  {x+1,y  });
            if(check(grid,x+1,y+1)) q.push({x+1,y+1});
            
            q.pop();
        }
    }
    
    bool check(vector<vector<char>>& grid, int x, int y){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) 
        {
            return 0;
        }
        else if(grid[x][y] == '1'){
            grid[x][y]= '0';
            return 1;
        }
        else return 0;
    }
};