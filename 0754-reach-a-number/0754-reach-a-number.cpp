class Solution {
public:
    int reachNumber(int t) {
        t = abs(t);
        int k = 0;
        while(t>0){
            t -= ++k;
        }
        return t%2 == 0 ? k : k+1+k%2;
    }
};