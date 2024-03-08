class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<int> b = {-1,0,1,-1,1,-1,0,1};
        vector<int> a = {-1,-1,-1,0,0,1,1,1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count = 0;
                for(int k=0; k<8; k++){
                    int I = i+a[k], J = j+b[k];
                    if(I < 0 || I >= n || J < 0 || J >= m) continue;
                    count += board[I][J]%10;
                }
                if(board[i][j] && count > 3){
                    
                }
                else if(board[i][j] && count > 1){
                    board[i][j] += 10;
                }
                else if(board[i][j]){
                    
                }
                else if(count == 3){
                    board[i][j] += 10;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j] /= 10;
            }
        }
        
    }
};