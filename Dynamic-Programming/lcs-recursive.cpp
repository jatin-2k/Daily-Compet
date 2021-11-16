int Lcs(int x, int y, string s1, string s2)
    {
        if(x==0 || y==0) return 0;
        if(dp[x][y] != -1) return dp[x][y]; 
        if(s1[x-1] == s2[y-1]){
            return dp[x][y] = Lcs(x-1, y-1, s1, s2) + 1;
        }
        else{
            return dp[x][y] =  max(Lcs(x,y-1, s1, s2),
                           Lcs(x-1,y, s1, s2));
        }
        return dp[x][y];
    }