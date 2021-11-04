class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool compare(pair<int,int>a, pair<int,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> p;
        int ans=0, *cmp= NULL;
        for(int i=0; i<n; i++){
            p.push_back({start[i],end[i]});
        }
        
        sort(p.begin(), p.end(), compare);
        for(auto &i: p){
            if(!cmp){
                cmp = &i.second;
                ans++;
            }
            else if(*cmp < i.first){
                ans++;
                cmp = &i.second;
            }
        }
        return ans;
    }
};