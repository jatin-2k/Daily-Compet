
bool check(int n, int i, int j){
    if(i>=0 && j>=0){
        return true;
    }
    return false;
}
int bfs(int i, int j, int e1, int e2){
    int n = 100;
        if(i==e1 && j==e2) return 1;
        if(i+1==e1 && j==e2) return 1;
        if(i-1==e1 && j==e2) return 1;
        if(i==e1 && j+1==e2) return 1;
        if(i==e1 && j-1==e2) return 1;
        if(i-1==e1 && j-1==e2) return 1;
        if(i-1==e1 && j+1==e2) return 1;
        if(i+1==e1 && j-1==e2) return 1;
        if(i+1==e1 && j+1==e2) return 1;

    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > arr;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        arr.push_back({x,y});
    }
    int ans = 0;
    pair<int,int> start = arr[0];
    for(int i=1; i<n; i++){
        pair<int,int> end = arr[i];
        int dis = bfs( start.first, start.second, end.first, end.second);
        if(dis<0){
            cout<<-1;
            return 0;
        }
        else{
            ans++;
        }
        start = end;
    }
    cout<<ans<<endl;
    return 0;
}