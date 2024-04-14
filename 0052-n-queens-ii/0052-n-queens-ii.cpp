class Solution {
public:
    int n;
    int ans = 0;
    set<vector<int>> qpos;
    
    int totalNQueens(int n){
        this->n=n;
        solve(0);
        return ans;
    }
    
    void solve(int j) {
        if(j == n){
            ans++;
            return;
        }
        for(int i=0; i<n; i++){
            if(safe(i,j)){
                qpos.insert({i,j});
                solve(j+1);
                qpos.erase({i,j});
            }
        }
    }

    bool safe(int x, int y){
        for(auto pos: qpos){
            int i = pos[0], j = pos[1];
            if(i == x || j == y) return false;
            if(abs(i-x) == abs(j-y)) return false;
        }
        return true;
    }
};