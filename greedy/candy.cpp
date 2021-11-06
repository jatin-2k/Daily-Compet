class Solution {
public:
    int candy(vector<int>& ratings) {
        
        vector<int> candy(ratings.size(),1);
        int ext=0;
        for(int i=0;i<ratings.size();i++)
        {
            if(i-1>=0 and ratings[i-1]<ratings[i])
            {
                candy[i]=candy[i-1]+1;
            }
        }
        
        for(int i=ratings.size()-1;i>=0;i--)
        {
            if(i+1<ratings.size() and ratings[i+1]<ratings[i] )
            {
                candy[i]=max(candy[i],candy[i+1]+1);
            }
        }
        
        for(auto &i:candy)
        {
            cout<<i<<" ";
            ext+=i;
        }
        return ext;
    }
};