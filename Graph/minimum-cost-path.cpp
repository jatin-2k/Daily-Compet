class Compare
{
public:
    bool operator() (pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
    {
        return a.first > b.first;
    }
};


class Solution
{
    public:
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare> minH;
    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int V = grid.size();
        vector<vector<int>> dis(V, vector<int>(V,INT_MAX));
        vector<vector<bool>> taken(V, vector<bool>(V,0));
        dis[0][0] = grid[0][0];
        minH.push({dis[0][0], {0,0}});
        while(!taken[V-1][V-1] && !minH.empty()){
            int curi = -1, curj = -1;
            curi = minH.top().second.first;
            curj = minH.top().second.second;
            minH.pop();
            while(taken[curi][curj]){
                curi = minH.top().second.first;
                curj = minH.top().second.second;
                minH.pop();
            }
            //cout<<curi<<" "<<curj<<endl;
            taken[curi][curj] = 1;
            if(check(curi-1, curj, taken, dis, grid, dis[curi][curj]));
            if(check(curi+1, curj, taken, dis, grid, dis[curi][curj]));
            if(check(curi, curj-1, taken, dis, grid, dis[curi][curj]));
            if(check(curi, curj+1, taken, dis, grid, dis[curi][curj]));
            
        }
        return dis[V-1][V-1];
    }
    
    bool check(int i,
               int j, 
               vector<vector<bool>>& taken, 
               vector<vector<int>>& dis,
               vector<vector<int>>& grid,
               int par){
        if( i<0 || j<0 || i>=taken.size() || j>=taken.size() || taken[i][j] || dis[i][j] < par + grid[i][j]){
            return false;
        }
        dis[i][j] = par + grid[i][j];
        minH.push({dis[i][j],{i,j}});
        return true;
    }
};