class Sol{
    public:
    vector<vector<int> > attack;
    Sol(){
        attack = vector<vector<int> >(8 , vector<int>(8,0));
    }
    void fun(char s1,char s2){
        check(s1-2,s2-1);
        check(s1-2,s2+1);
        check(s1+2,s2+1);
        check(s1+2,s2-1);
        check(s1-1,s2-2);
        check(s1-1,s2+2);
        check(s1+1,s2-2);
        check(s1+1,s2+2);
    }
    void check(char s1, char s2){
        if(s1>='A' && s2>='1' && s1<='H' && s2 <='8'){
            attack[s2-'1'][s1-'A']++;
        }
    }
};

int main(){
    string s;
    cin>>s;
    int len=s.size();
    Sol a;
    for(int i=0; i<len; i+=2){
        a.fun(s[i],s[i+1]);
    }
    // for(int i=0; i<8; i++){
    //     for(int j=0; j<8; j++){
    //         cout<<a.attack[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int maxn = INT_MIN;
    int total = 8*8;
    int m1=0,m2=0;
    int countm = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(a.attack[i][j] > 0){
                total--;
                if(a.attack[i][j] > maxn){
                    maxn = a.attack[i][j]; m1 = i; m2=j; countm = 1;
                }
                else if(a.attack[i][j] == maxn){
                    countm++;
                }
            } 
        }
    }
    cout<<total<<endl;
    if(countm != 1) cout<<-1<<endl;
    else{
        char c = m2+'A';
        cout<<c<<m1+1<<endl;
    }
    return 0;
}