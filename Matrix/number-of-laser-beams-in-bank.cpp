class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int curD = 0, ans = 0, r = bank.size(), c = bank[0].size();
        vector<int> devices;
        for(int i=0; i<r; i++){
            curD = 0;
            for(int j=0; j<c; j++){
                if(bank[i][j]=='1'){
                    curD++;
                }
            }
            if(curD > 0){
                devices.push_back(curD);
            }
        }
        for(int i=1; i<devices.size(); i++)
        {
            ans += devices[i]*devices[i-1];
        }
        return ans;
    }
};