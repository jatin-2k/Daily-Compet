class Solution
{   
    public:
    //Function to multiply two matrices.
    vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        // code here
        int r1=A.size(), r2=B.size(), c1=A[0].size(), c2 = B[0].size();
        vector<vector<int>> ans(r1, vector<int>(c2));
        if(c1==r2){
            for(int i=0; i<c2 ; i++){
                for(int j=0; j<r1; j++){
                    for(int k=0; k<c1; k++){
                        ans[j][i] += A[j][k]*B[k][i];
                    }
                }
            }
        }
        else{
            ans = {{-1}};
        }
        return ans;
    }
};