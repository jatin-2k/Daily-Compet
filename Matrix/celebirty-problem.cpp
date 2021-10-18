class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) 
    {
        // code here
        int i=0,j=0;
        for(; i<n; i++){
            while(a[j][i]==1){
                j++;
            }
        }
        //if celeb is imaginary
        if(j>n) return -1;
        //she knows no one
        for(i=0; i<n; i++){
            if(a[j][i] == 1) return -1;
        }
        //everyone knws hin
        for(i=0; i<n; i++){
            if(i!=j and a[i][j]==0) return -1;
        }
        return j;
    }
};