int findDuplicate(vector<int> &a){
    int x = 0;
    for(int i: a){
        x = x^i;
    }
    return x;
}
