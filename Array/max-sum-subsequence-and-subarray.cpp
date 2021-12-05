vector<int> maxSubarray(vector<int> arr) {
    int ss=0, sa =0;
    int cur=0, max=arr[0];
    for(auto i: arr){
        if(i>0) ss+=i;
        cur+=i;
        if(cur<0){
            cur=0;
            max = std::max(max, i);
        }
        else if(max<cur) max= cur;
    }
    sa = max;
    if(ss == 0) ss = max;
    return {sa,ss};
}