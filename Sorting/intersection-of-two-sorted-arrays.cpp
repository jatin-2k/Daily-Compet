class Solution{
    public:
    //Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(int a[], int b[], int n, int m) 
    { 
        //Your code here
        int i=0, j=0;
        vector<int> ans;
        while(i<n and j<m){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                
                i++;j++;
            }
            else (a[i]<b[j])?i++:j++;
        }
        ans.erase(unique(ans.begin(),ans.end()), ans.end());
        if(ans.size()==0) ans.push_back(-1);
        return ans;
    }

};