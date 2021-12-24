class Sol{
    public:
        vector<int> fill(int top, int bottom, int left, int right, vector<vector<int> >& arr, int d){
            vector<int> ans;
            for(int i=left; i<=right; i++) 
                ans.push_back(arr[top][i]);
            top++;
            for(int i=top; i<=bottom; i++) 
                ans.push_back(arr[i][right]);
            right--;
            if(bottom>=top)
            for(int i=right; i>=left; i--) 
                ans.push_back(arr[bottom][i]);
            bottom--;
            if(left <= right)
            for(int i=bottom; i>=top; i--) 
                ans.push_back(arr[i][left]);
            left++;

            rotateArr(ans, d, ans.size());
            return ans;
        }
        void fun(int& top, int& bottom, int& left, int& right, vector<vector<int> >& arr, int d){
            vector<int> ans = fill(top,bottom,left,right,arr,d);
            int it = 0;
            for(int i=left; i<=right; i++) arr[top][i] = ans[it++];
            top++;
            for(int i=top; i<=bottom; i++) arr[i][right] = ans[it++];
            right--;
            if(bottom>=top)
            for(int i=right; i>=left; i--) arr[bottom][i] = ans[it++];
            bottom--;
            if(left<=right)
            for(int i=bottom; i>=top; i--) arr[i][left] = ans[it++];
            left++;
        }
        void rotateArr(vector<int>& arr, int d, int n){
            reverse(arr.begin(),arr.begin()+d);
            reverse(arr.begin()+d, arr.end());
            reverse(arr.begin(),arr.end());
        }
};