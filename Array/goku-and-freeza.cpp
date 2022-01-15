#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--){
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    int temp;
    for (int i=0; i<n;i++){
      cin>>temp;
      mp[temp]++;

    }
    while(n>=0){
      if (n==0){
        cout<<"YES"<<endl;
        break;
      }
      else if (mp[n]==0){
        cout<<"NO"<<endl;
        break;
      }
      else{
        int t =mp[n];
        mp[n] =0;
        n= n-t;
      }
    }

  }
  
  return 0;
}