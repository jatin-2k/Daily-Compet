class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int cur = 0;
        for(int i=0; i<n; i++) cur+=gas[i];
        for(int i=0; i<n; i++) cur-=cost[i];
        if(cur < 0) return -1;
        
        int start = 0;
        int end = 0;
        cur = 0;
        
        do{
            cur += gas[end]-cost[end];
            if(cur >= 0){
                end = (end+1)%n;
                if(end==start) return start;
            }
            else{
                start = end+1;
                end = (end+1)%n;
                cur = 0;
            }
        }while(start<n);
        return -2;
    }
};