class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int ind = 0;
        while(!columnTitle.empty()){
            ans += (columnTitle.back() - 'A' + 1) * pow(26,ind);
            ind++;
            columnTitle.pop_back();
        }
        return ans;
    }
};