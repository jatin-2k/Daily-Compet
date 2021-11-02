class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> minH(arr, arr+n);
        long long ans = 0;
        while(minH.size()>1){
            long long p1 = minH.top();
            minH.pop();
            long long p2 = minH.top();
            minH.pop();
            ans+=p1+p2;
            minH.push(p1+p2);
        }
        return ans;
    }
};