class Solution {
public:
    int maximumGood(vector<vector<int>>& S) {
        int n = size(S), ans = 0;
        auto valid = [&](int cur) {
            for(int i = 0; i < n; i++)
                if(cur & 1 << n-1-i) // if cur config says ith person from last is good 
                    for(int j = 0; j < n; j++) // if ith person from last isn't 
                        if(S[i][j] != 2 && S[i][j] != bool(cur & 1 << n-1-j)) return false;
            return true;
        };
        for(int i = 0; i < 1 << n; i++){   
            if(valid(i)) ans = max(ans, __builtin_popcount(i));    // update ans if valid config
        }
        return ans;
    }
};