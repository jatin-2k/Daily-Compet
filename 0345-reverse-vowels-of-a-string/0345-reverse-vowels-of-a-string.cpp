class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int i=0; int j=n-1;
        while(i<j){
            while(i<j && !isVovel(s[i])) i++;
            while(i<j && !isVovel(s[j])) j--;
            if(i<j) swap(s[i], s[j]);
            i++, j--;
        }
        return s;
    }
    
    bool isVovel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
};