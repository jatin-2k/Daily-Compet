class Solution {
public:
    int strStr(string hay, string needle) {
        int n = hay.size(), m = needle.size();
        if(n<m) return -1;
        if(m==0) return 0;
        for(int i=0; i<n; i++){
            if(hay[i]==needle[0]){
                int ci=i,cj=0;
                while(cj < m and hay[ci] == needle[cj]) ci++,cj++;
                if(cj == m) return i;
            }
        }
        return -1;
    }
};