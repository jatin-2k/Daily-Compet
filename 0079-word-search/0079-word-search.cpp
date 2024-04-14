class Solution {
public:
    vector<vector<bool>> v;
    int n,m;
    vector<vector<char>> arr;
    bool found = false;
    bool exist(vector<vector<char>>& a, string t) {
        n = a.size();
        m = a[0].size();
        v = vector<vector<bool>>(n, vector<bool>(m));
        arr = a;
        for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++){
            if(!found && arr[i][j] == t.back()) consider(i,j,t);
        }
        //cout<<endl;
        return found;
    }
    
    void find(int i, int j, string t){
        if(t == ""){
            found = true;
            return;
        }
        if(found) return;
        if(i>0 && !v[i-1][j] && arr[i-1][j] == t.back()) consider(i-1,j,t);
        if(j>0 && !v[i][j-1] && arr[i][j-1] == t.back()) consider(i,j-1,t);
        if(i<n-1 && !v[i+1][j] && arr[i+1][j] == t.back()) consider(i+1,j,t);
        if(j<m-1 && !v[i][j+1] && arr[i][j+1] == t.back()) consider(i,j+1,t);
    }
    
    void consider(int i, int j, string &t){
        char c = t.back();
        //cout<<c<<" ";
        v[i][j] = 1;
        t.pop_back();
        find(i,j,t);
        t += c;
        v[i][j] = 0;
    }
};