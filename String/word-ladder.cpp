class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (wordDict.find(endWord) == wordDict.end()) {
            return 0;
        }
        unordered_set<string> beginSet = {beginWord};
        unordered_set<string> endSet = {endWord};
        int step = 1;
        while (!beginSet.empty()) {
            unordered_set<string> tempSet;
            for (auto& word : beginSet) {
                wordDict.erase(word);
            }
            for (auto& word : beginSet) {
                for (int i = 0; i < word.size(); ++i) {
                    string curr = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        curr[i] = ch;
                        if (endSet.find(curr) != endSet.end()) {
                            return step + 1;
                        } else if (wordDict.find(curr) != wordDict.end()) {
                            tempSet.insert(curr);
                        }
                    }
                }
            }
            step += 1;
            if (tempSet.size() > endSet.size()) {
                beginSet = endSet;
                endSet = tempSet;
            } else {
                beginSet = tempSet;
            }
        }
        return 0;
    }
};