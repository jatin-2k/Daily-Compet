#include<bits/stdc++.h>
using namespace std;

long long int bound(vector<vector<int> >& arr,int n, int m){
    int top = 0, bottom = n-1, left = 0, right = m-1;
    long long int ans = 0;
    for(int i=left; i<=right; i++){
        ans+=arr[top][i];
    }
    top++;
    for(int i=top; i<=bottom; i++){
        ans+=arr[i][right];
    }
    right--;
    if(bottom >= top)
    for(int i=right; i>=left; i--){
        ans+=arr[bottom][i];
    }
    bottom--;
    if(left<=right)
    for(int i=bottom; i>=top; i--){
        ans+=arr[i][left];
    }
    left++;
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > arr(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Sum of boundary is "<<bound(arr,n,m);
    return 0;
}