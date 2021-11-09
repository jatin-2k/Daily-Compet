long long minimumNumberOfCoins(int coins[],int nc,int value)
    {
        long long dp[value+1] ;
        dp[0] = 0 ;
        
        for(int i=1 ; i<=value ;i++)
          dp[i] = INT_MAX ;
          
        for(int i=1; i<=value; i++ ){
            for(int j=0; j<nc; j++){
                if(coins[j] <= i){
                    long long sub = dp[i- coins[j]];
                    if(sub != INT_MAX){
                        dp[i] = min(dp[i], sub+1);
                    }
                }
            }
        }
        if(dp[value] == INT_MAX or dp[value] == 0)
          return -1 ;
        
        else 
          return dp[value] ;
    }