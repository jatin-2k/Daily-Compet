class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        priority_queue<int, vector<int>, greater<int>> minH;
        vector<int> ans;
        for(int i=0; i<num; i++){
            minH.push(arr[i]);
            if(minH.size()>K){
                ans.push_back(minH.top());
                minH.pop();
            }
        }
        while(!minH.empty()){
            ans.push_back(minH.top());
            minH.pop();
        }
        return ans;
    }
};