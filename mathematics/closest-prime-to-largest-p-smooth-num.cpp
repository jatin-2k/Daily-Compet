bool isPrime(int n) {
   if (n == 2) {
      return true;
   }
   for (int i = 2; i <= ceil(sqrt(n)); i++) {
      if (n % i == 0) {
         return false;
      }
   }
   return true;
}

int primeb(int n) {
   for (int i = n - 1; i > 1; i--) {
      if (isPrime(i)) {
         return i;
      }
   }
   return 0;
}

int primea(int n) {
   for (int i = n; i < n*2; i++) {
      if (isPrime(i)) {
         return i;
      }
   }
   return 0;
}

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

bool check(int i, int p){
    return gpf(i)<=p;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(),arr.end());
    int p;
    cin>>p;
    for(auto i: arr){
        if(check(i,p)){
            int b = primeb(i);
            int a = primea(i);
            if(i-b <= a-i) {
                cout<<b;
            }
            else cout<<a;
            break;
        }
    }
    return 0;
}