int spf(int num){
    while(num%2 == 0) {
        return 2;
    }
    for(int i=3; i<=sqrt(num); i=i+2){
        while(num%i==0){
            return i;
            num/=i;
        }
    }
    return num;
}