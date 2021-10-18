class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > a, int n, int m, int x) 
    {
        // code here 
        int i=0, j=m-1;
        while(i<n && j>=0){
            if(a[i][j]==x) return true;
            if(a[i][j]<x) i++;
            else          j--;
        }
        return false;
    }
};