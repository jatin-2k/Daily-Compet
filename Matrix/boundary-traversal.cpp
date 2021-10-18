class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > a, int n, int m) 
    {
        // code here
        vector<int> ans;
        int top=0, bottom=n-1, right=m-1, left=0;
            for(int i=left; i<=right; i++){
                ans.push_back(a[top][i]);
            }
            top++;
            for(int i=top; i<=bottom; i++){
                ans.push_back(a[i][right]);
            }
            right--;
            if(bottom >= top)
            for(int i=right; i>=left; i--){
                ans.push_back(a[bottom][i]);
            }
            bottom--;
            if(left <= right)
            //cout<<"b:"<<bottom<<"t"<<top<<"l:"<<left<<endl;
            for(int i=bottom; i>=top; i--){
                ans.push_back(a[i][left]);
            }
            left++;
            return ans;
    }
};