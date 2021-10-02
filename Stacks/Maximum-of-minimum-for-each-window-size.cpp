class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> l,r;
        l = toLeft(arr,n);
        r = toRight(arr,n);
        vector<int> ans(n+1);
        for(int i=0; i<n; i++)
        {
            int len = r[i]-l[i]-1;
            ans[len] = max(ans[len], arr[i]);
        }
        
        for(int i=n-1; i>0; i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        vector<int> a;
        for(int i=1; i<=n; i++){
            a.push_back(ans[i]);
        }
        return a;
    }
    
    vector<int> toLeft(int arr[],int n){
        stack<pair<int,int>> s;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(s.empty()) ans.push_back(-1);
            else if(s.top().first < arr[i]){
                ans.push_back(s.top().second);
            }
            else if(s.top().first >= arr[i]){
                while(!s.empty() && s.top().first >= arr[i]){
                    s.pop();
                }
                if(s.empty()) ans.push_back(-1);
                else ans.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        return ans;
    }
    vector<int> toRight(int arr[],int n){
        stack<pair<int,int>> s;
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            if(s.empty()) ans.push_back(n);
            else if(s.top().first < arr[i]){
                ans.push_back(s.top().second);
            }
            else if(s.top().first >= arr[i]){
                while(!s.empty() && s.top().first >= arr[i]){
                    s.pop();
                }
                if(s.empty()) ans.push_back(n);
                else ans.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};