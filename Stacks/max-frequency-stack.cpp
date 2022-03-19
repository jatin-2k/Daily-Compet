class FreqStack {
public:
    map<int,int> freq;
    map<int, stack<int>> group;
    int maxFreq;
    
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int f = ++freq[val];
        if(f > maxFreq)
            maxFreq = f;
        group[f].push(val);
    }
    
    int pop() {
        int x = group[maxFreq].top();
        group[maxFreq].pop();
        freq[x]--;
        if(group[maxFreq].empty())
            maxFreq--;
        return x;
    }
};