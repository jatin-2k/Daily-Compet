class Solution {
public:
    void rev(string &s, int i, int j){
        j--;
        while(i<j){
            swap(s[i],s[j]);
            i++,j--;
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            int j=i;
            while(j<n and s[j]!=' ') j++;
            rev(s,i,j);
            i = j;
        }
        return s;
    }
};