class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(); bool isSmall = false;
        if(n<2) return true;
        if(word[0] > 91) isSmall=true;
        if(word[1] < 91 && isSmall) return false;
        else{
            if(!isSmall && word[1] > 91) isSmall = true;
            //cout<<"here"<<word<<endl;
            for(int i=1; i<n; i++){
                if(isSmall && word[i] < 91) return false;
                else if(!isSmall && word[i] > 91) return false;
            }
            return true;
        }
    }
};