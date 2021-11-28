class Solution
{
    public:
    vector<char> key_pad[10] =
    {
        {}, {},        // 0 and 1 digit don't have any characters associated
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's'},
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z'}
    };
    static bool my_compare(string a, string b)
    {
        if (a.compare(0, b.size(), b) == 0
            || b.compare(0, a.size(), a) == 0)
      
            return a.size() > b.size();
        else
            return a < b;
    }
    void findCombinations(vector<char> keypad[],
                      int input[], string res, int index, vector<string> &ans)
    {
        if (index == -1) {
            ans.push_back(res);
            return;
        }
        int digit = input[index];
        int len = keypad[digit].size();
        for (int i = 0; i < len; i++) {
            findCombinations(keypad, input, keypad[digit][i] + res, index - 1,ans);
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        findCombinations(key_pad,a,string(""),N-1,ans);
        sort(ans.begin(), ans.end(), my_compare);
        return ans;
    }
};