class Solution {
public:
    void add(int &n){
        int ans = 0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        n=ans;
    }
    int addDigits(int num) {
        while(num > 9){
            add(num);
        }
        return num;
    }
};