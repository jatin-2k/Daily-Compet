class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int dis = 1, disb = 0, disa = 0;
        int mx = 0;
        int i=0, n = seats.size()-1;
        while(i<=n && !seats[i]){
            disb++; i++;
        }
        while(n>i && !seats[n]){
            disa++; n--;
        }
        for(; i<=n; i++){
            dis = 1;
            while(i<=n && !seats[i]){
                dis++; i++;
            }
            mx = max(mx,dis);
        }
        cout<<disb<<" "<<mx/2<<" "<<disa<<endl; 
        return max({disa,disb, mx/2});
    }
};