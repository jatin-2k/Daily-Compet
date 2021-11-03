class Compare
{
public:
    bool operator() (pair<char, int> a, pair<char, int> b)
    {
        if (a.second == b.second) 
                return a.first > b.first; 
        return a.second < b.second;
    }
};

class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    string rearrangeString(string str)
    {
        // Your code here
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> maxH;
        string s = "";
        {
            unordered_map<char, int> m;
            for(auto i: str){
                m[i]++;
            }
            for(auto i: m){
                maxH.push(i);
            }
        }
        
        pair<char, int> last = maxH.top();
        maxH.pop();
            
        s+=last.first;
        last.second--;
        
        while(!maxH.empty()){
            pair<char, int> cur = maxH.top();
            maxH.pop();
            
            s+=cur.first;
            cur.second--;
            
            if(last.second > 0)
            maxH.push(last);
            last = cur;
        }
        return s;
    }
};