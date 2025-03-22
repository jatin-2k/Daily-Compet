class Solution {
    public:
        string reverseWords(string s) {
            int n = s.size();
            stringstream ss(s);
            string word;
            string res = "";
            while (ss >> word) {
                res = word + " " + res;
            }
            return res.substr(0, res.size()-1);
        }
    };