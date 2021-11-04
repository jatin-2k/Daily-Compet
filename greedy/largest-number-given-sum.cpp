string largestNumber(int n, int sum)
    {
        // Your code here
        string s="";
        while(sum>0){
            if(sum>=9){
                s+='9';
                sum-=9;
            }
            else{
                s+=sum+'0';
                sum = 0;
            }
            if(s.length()>n){
                return "-1";
            }
        }
        while(s.length()<n){
            s+='0';
        }
        return s;
    }