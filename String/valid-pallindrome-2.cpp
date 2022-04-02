class Solution {
public:
    bool validPalindrome(string s, int i=0, int j=-1, bool deleted = false) {
        if(j==-1) i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                if(deleted) return false;
                return validPalindrome(s, i, j-1, 1) || validPalindrome(s, i+1, j, 1);
            }
            i++,j--;
        }
        return true;
    }
};