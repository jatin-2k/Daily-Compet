class Solution {
public:
    bool canPlaceFlowers(vector<int>& planted, int x) {
        planted.insert(planted.begin(), 0);
        planted.push_back(0);
        int i=1, n=planted.size()-1, count=0;
        while(i<n){
            if(!planted[i-1] && !planted[i] && !planted[i+1]){
                count++; i++;
            }
            i++;
        }
        cout<<count<<endl;
        return count >= x;
    }
};