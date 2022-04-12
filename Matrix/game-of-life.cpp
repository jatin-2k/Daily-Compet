class Solution {
public:
    int calc(vector<vector<int>>& board, int i, int j, int &r, int &c){
        vector<int> x = {-1,0,1,-1,1,-1,0,1};
        vector<int> y = {-1,-1,-1,0,0,1,1,1};
        int ans = 0;
        for(int k=0; k<8; k++){
            if(i+x[k]>=0 and i+x[k]<r and j+y[k]>=0 and j+y[k]<c){
                if(board[i+x[k]][j+y[k]]) ans++;
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size(), c = board[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int ne = calc(board, i, j, r, c);
                if(ne < 2) ans[i][j] = 0;
                if(ne == 3) ans[i][j] = 1;
                if(ne > 3) ans[i][j] = 0;
                if(ne == 2) ans[i][j] = board[i][j];
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                board[i][j] = ans[i][j];
            }
        }
    }
};