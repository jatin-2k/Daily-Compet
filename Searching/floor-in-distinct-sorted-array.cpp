class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        auto it = lower_bound(v.begin(), v.end(), x);
        if(*it==x){
            return it-v.begin();
        }
        else return it-1-v.begin();
    }
};