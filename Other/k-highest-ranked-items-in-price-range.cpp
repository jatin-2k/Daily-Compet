class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pr, vector<int>& start, int k) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> arr;
        vector<int> rs = {+1,-1,0,0}, cs = {0,0,+1,-1};
        vector<vector<bool>> visited(r,vector<bool>(c,0));
        visited[start[0]][start[1]]=true;
        queue<vector<int>> q;
        q.push({0,grid[start[0]][start[1]], start[0], start[1]});
        while(!q.empty()){
            vector<int> cur = q.front(); q.pop();
            for(int i=0; i<4; i++){
                int cr = cur[2]+rs[i], cc = cur[3]+cs[i];
                if(cr>=0 and cc>=0 and cr<r and cc<c and !visited[cr][cc] and grid[cr][cc]){
                    visited[cr][cc] = true;
                    q.push({cur[0]+1, grid[cr][cc], cr, cc});
                }
            }
            arr.push_back(cur);
        }
        
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(auto &node: arr){
            if(ans.size()==k) break;
            if(node[1]!=1 and node[1]<=pr[1] and node[1]>=pr[0]){
                ans.push_back({node[2],node[3]});
            }
        }
        return ans;
    }
};