class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
        vector<int> ans;
        int d = b * b - 4 * a * c;
        double sqrt_val = sqrt(abs(d));
        
        if(d>0){
            ans.push_back( floor((-b + sqrt_val) / (2 * a)) );
            ans.push_back( floor((-b - sqrt_val) / (2 * a)) );
            sort(ans.begin(), ans.end(), greater<int>());
        }
        else if(d==0){
            ans.push_back(floor(-b / (2 * a)));
            ans.push_back(floor(-b / (2 * a)));
        }
        else{
            ans.push_back(-1);
        }
        return ans;
    }
};
