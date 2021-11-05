static bool srt(const struct val &a,const struct val &b){
    return a.second < b.second;
}
int maxChainLen(struct val p[],int n)
{
    sort(p ,p + n,srt);
    int res = 0;
    for(int i = 0 ; i < n ; i ++){
        int size = 1;
        int chk = p[i].second;
        for(int j = i + 1 ; j < n ; j++){
            if(p[j].first > chk){
                size++;
                chk = p[j].second;
            }
        }
        res = max(res,size);
    }
    return res;
}