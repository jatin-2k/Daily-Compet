class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long numberOfWays(int coins[],int numberOfCoins,int value)
    {
        int ways[value+1];
        for(int i=0; i<=value; i++){
            ways[i]=0;
        }
        ways[0] = 1;
        for(int i=0; i<numberOfCoins; i++){
            for(int j=1; j<=value; j++){
                if(j>=coins[i]){
                    ways[j] = ways[j]+ways[j-coins[i]];
                }
            }
        }
        return ways[value];
    }
};