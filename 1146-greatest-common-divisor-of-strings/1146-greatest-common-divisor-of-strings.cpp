class Solution {
public:
    string gcdOfStrings(string a, string b) {
        if(a.size() > b.size()) swap(a,b);
        int x = a.size(), y = b.size();
        for(int i=x; i>0; i--) {
            if(x%i!=0 || y%i!=0) continue;
            cout<<"checking = "<<i<<endl;
            bool gg = true;
            for(int j=0; j<x && gg; j++) {
                cout<<"cmp = "<<a[j]<<","<<a[j%i]<<endl;
                if(a[j] != b[j%i]) gg = false;
            }
            for(int j=0; j<y && gg; j++) {
                if(b[j] != a[j%i]) gg = false;
            }
            if(gg) return a.substr(0,i);
        }
        return {};
    }
};