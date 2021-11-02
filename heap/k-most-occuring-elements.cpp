class Compare
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second) 
                return a.first < b.first; 
        return a.second > b.second;
    }
};

class Solution
{
    public:
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    int kMostFrequent(int arr[], int n, int k) 
    { 
        // Your code here    
        map<int, int> map;
        for(int i=0; i<n; i++){
            map[arr[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, Compare> minH;
        for(auto i: map){
            minH.push(i);
            if(minH.size() > k) minH.pop();
        }
        int ans=0;
        while(!minH.empty()){
            //cout<<minH.top().first<<" "<<minH.top().second<<endl;
            ans+=minH.top().second;
            minH.pop();
        }
        return ans;
    } 
};