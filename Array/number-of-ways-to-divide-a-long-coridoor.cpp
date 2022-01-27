class Solution {
public:
    int numberOfWays(string s) {
        int n = s.size(), m = 1e9+7; 
        long long ans = 1, count = 0, seats = 0, plants = 0;
        for(int i=n-1; i>=0; i--) seats+=(s[i]=='S');
        if(n<2 || seats%2 || !seats) return 0;
        for(int i=n-1; i>=0; i--){
            ans = (ans*(plants+1))%m;
            plants=0;
            if(s[i]=='S'){
                i--;
                while(i>=0 && s[i]!='S') i--;
                i--;
                while(i>=0 && s[i]!='S'){
                    plants++; i--;
                }
                i++;
            }
        }
        return ans;
    }
};