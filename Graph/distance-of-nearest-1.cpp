class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int r = grid.size();
	    int c = grid[0].size();
	    queue<pair<int,int>> q;
	    vector<vector<int>> ans(r, vector<int>(c,-1));
	    for(int i=0; i<r; i++){
	        for(int j=0; j<c; j++){
	            if(grid[i][j]){ 
	                q.push({i,j});
	                ans[i][j]=0;
                }
	        }
	    }
	    while(!q.empty()){
	        int i = q.front().first;
	        int j = q.front().second;
	        q.pop();
	        if(check(i-1,j  ,r,c,ans,ans[i][j])) q.push({i-1,j  });
	        if(check(i  ,j-1,r,c,ans,ans[i][j])) q.push({i  ,j-1});
	        if(check(i+1,j  ,r,c,ans,ans[i][j])) q.push({i+1,j  });
	        if(check(i  ,j+1,r,c,ans,ans[i][j])) q.push({i  ,j+1});
	    }
	    return ans;
	}
	
	bool check(int i, int j, int r,int c, vector<vector<int>>&ans, int par){
	    if(i<0 || j<0 || i>=r || j>=c || ans[i][j]!= -1) return false;
	    if(ans[i][j]==-1){ 
	        ans[i][j] = par+1;
	        return true;
	    }
	}
};