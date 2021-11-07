class Solution {
public:
    unordered_map<char,int>mp;
    bool isvowel(char q)
    {
        if(q=='a' or q=='e' or q=='i' or q=='o' or q=='u' )
        {
            return true;
        }
        return false;
    }
    
    bool allvowel()
    {
        if(mp['a']>0 and mp['e']>0 and mp['i']>0 and mp['o']>0 and mp['u']>0 )
        {
            return true;
        }
        return false;
    }

    int countVowelSubstrings(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isvowel(s[i]))
            {
                mp.clear();
                for(int j=i;j<n;j++)
                {
                    // cout<<s[j];
                    if(!isvowel(s[j]))
                    {
                        break;
                    }
                     mp[s[j]]++;
                    if(allvowel())
                    {
                        count++;
            
                    }

                }
            }
 
        }
        return count;
    }
};