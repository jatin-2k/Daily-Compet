class WordDictionary {
public:
    map<int, vector<string>> mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto &cur: mp[word.size()]){
            int i=0;
            for(; i<word.size(); i++){
                if(word[i]!='.' && word[i]!=cur[i] ) break;
            }
            if(i==word.size()) return true;
        }
        return false;
    }
};