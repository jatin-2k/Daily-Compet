class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    
    void booleanMatrix(vector<vector<int> > &a)
    {
        // code here 
        int n=a.size(), m=a[0].size();
        //cout<<n<<" "<<m<<" "<<endl;
        vector<vector<int> > ans(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 1){
                    a[0][j] = 1;
                    a[i][0] = 1;
                }
            }
        }
        for(int j=0; j<m; j++){
            int i=0;
            if(a[i][j] == 1){
                while(i<n){
                    ans[i++][j] =1;
                }
            }
        }
        for(int i=0; i<n; i++){
            int j=0;
            if(a[i][j]==1){
                while(j<m){
                    ans[i][j++] = 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a[i][j] = ans[i][j];
            }
        }
    }
};
//{{ 1, 0, 0},
// { 1, 0, 0},
// { 1, 0, 0},
// { 0, 0, 0}}
//to
//1 1 1
//1 1 1
//1 1 1
//1 0 0 