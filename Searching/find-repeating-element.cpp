class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        vector<int> ans;
        for(int i = 0; i < n+2; i++) 
          { 
            if(arr[abs(arr[i])] > 0) 
              arr[abs(arr[i])] = -arr[abs(arr[i])]; 
            else
              ans.push_back(abs(arr[i]));
          } 
          return ans;
    }
};