class Solution {
public:
    static bool compare(vector<int> a ,vector<int> b)    
    {
        // if(a[1]==b[1])
        // {
        //     return a[0]<b[0];
        // }
        return a[1]<b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        
        sort(points.begin(),points.end(),compare);
        int ans=1;
        int compare=points[0][1];
        
       for(auto &i:points)
       {
           if(i[0]>compare)
               ans++,compare=i[1];
       }
        return ans;
        
    }
};