class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i1=0,i2=0;
        int n1 = v1.size(), n2 = v2.size();
        int ans = 0;
        while(i1<n1 or i2<n2){
            int num1 = 0, num2 = 0;
            while(i1<n1 and v1[i1]!='.'){
                num1 = num1 * 10 + v1[i1] - '0';
                i1++;
            }
            while(i2<n2 and v2[i2]!='.'){
                num2 = num2 * 10 + v2[i2] - '0';
                i2++;
            }
            if(num1 > num2){
                return 1;
            }
            if(num2 > num1){
                return -1;
            }
            i1++;
            i2++;
        }
        return 0;
    }
};