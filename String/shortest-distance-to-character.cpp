class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> dis(n,-1);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(s[i]==c){
                dis[i]=0;
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            if(cur<n-1 && dis[cur+1] == -1){
                dis[cur+1] = dis[cur]+1;
                q.push(cur+1);
            }
            if(cur>0 && dis[cur-1] == -1){
                dis[cur-1] = dis[cur]+1;
                q.push(cur-1);
            }
        }
        return dis;
    }
};