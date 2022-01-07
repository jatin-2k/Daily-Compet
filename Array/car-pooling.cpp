class Solution {
public:
    vector<int> d = vector<int>(1001, 0);
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(auto i: trips){
            d[i[1]] += i[0];
            d[i[2]] -= i[0];
        }
        int count = 0;
        for(int i=0; i<1001; i++){
            count += d[i];
            if(count > capacity) return false;
        }
        return true;
    }
};