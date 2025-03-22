class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        for(int i=0; i<101; i++){
            if(i<word1.size()) ans += word1[i];
            if(i<word2.size()) ans += word2[i];
        }
        return ans;
    }
};