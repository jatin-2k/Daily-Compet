class Solution {
public:
    int isev(int num){
        int ans = 0;
        while(num){
            ans+=num%10;
            num /= 10;
        }
        return ans%2==0 ? 1 : 0;
    }
    int countEven(int num) {
        int ans = 0;
        while(num){
            int temp = isev(num);
            //if(temp ==1 ) cout<<num<<" ";
            ans+=temp;
            num--;
        }
        return ans;
    }
};