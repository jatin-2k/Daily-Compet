typedef pair<int,int> pi;
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        priority_queue<pi, vector<pi>, greater<pi>> minH;
        string ans;
        int cur=-1;
        for(int i=0; i<n; i++){
            minH.push({num[i], i});
            while(minH.size() > k){
                ans += minH.top().first;
                cur = minH.top().second;
                minH.pop();
            }
            while(!minH.empty() && minH.top().second < cur){
                k--;
                minH.pop();
            }   
        }
        for(cur = 0;ans[cur] == '0' && cur < ans.size(); cur++);
        ans = ans.substr(cur);
        if(ans.size() == 0) return "0";
        return ans;
    }
};