 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int r, int c) 
    {
        // code here
        vector<int> ans;
        int top=0, bottom=r-1, left=0, right=c-1;
        while(top<=bottom && left <= right){
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
        }
        return ans;
    }
};