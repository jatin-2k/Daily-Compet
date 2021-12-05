vector<int> closestNumbers(vector<int> arr) {

    vector<int> ans;
    sort(arr.begin(), arr.end());
    int m = INT_MAX;
    int n = arr.size()-1;
    for(int i=0; i<n; i++){
        m = min(m, arr[i+1]-arr[i]);
    }
 
    for(int i=0; i<n; i++){
        if(arr[i+1]-arr[i] == m){
            ans.push_back(arr[i]);
            ans.push_back(arr[i+1]);
        }
    }
    return ans;
}