class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        k-=n;
        for(int i=n-1; i>=0; i--){
            if(k>25){
                ans[i]+=25; k-=25;
            }
            else{
                ans[i]+=k; k=0; break;
            }
        }
        return ans;
    }
};