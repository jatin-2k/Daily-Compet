class Solution 
{
    public:
    
    static bool comp(Job a, Job b){
        // if(a.profit==b.profit){
        //     return a.dead>b.dead;
        // }
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n,comp);
        int max = 0;
        for(int i=0; i<n; i++){
            if(arr[i].dead > max) max = arr[i].dead;
        }
        vector<int> s(max);
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead-1; j>=0; j--){
                if(s[j]==0){
                    s[j]=arr[i].profit;
                    break;
                }
            }
        }
        int count=0, ans =0;
        
        for(auto i: s){
            if(i!=0){
                ans+=i;
                count++;
            }
        }
        return {count,ans};
    } 
};