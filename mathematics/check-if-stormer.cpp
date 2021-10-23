int gpf(int num){
    int max = 2;
    while(num%2 == 0) {
        num = num / 2;
    }
    for(int i=3; i<=sqrt(num); i=i+2){
        while(num%i==0){
            max = i;
            num/=i;
        }
    }
    if(num > 1){
        max = num;
    }
    return max;
}
//function to check stormer number
bool gsn(int num){
    return gpf(num*num +1) >= 2*num; 
}