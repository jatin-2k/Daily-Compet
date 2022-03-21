class Solution {
public:
    vector<int> partitionLabels(string s) {
        int maxa[26] = {};
        for(int i=0; i<s.size(); i++){
            maxa[s[i]-'a']=i;
        }
        int range[s.size()];
        for(int i=0; i<s.size(); i++){
            range[i]=maxa[s[i]-'a'];
        }
        int count=0;
        vector<int> ans;
        int maxrange=0;
        for(int i=0; i<s.size(); i++){
            maxrange=max(maxrange, maxa[s[i]-'a']);
            count++;
            if(maxrange==i){
                ans.push_back(count);
                count=0;
            }
        }
        return ans;
    }
};