class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startStation=0, n=gas.size(), driven = 0, end = 0;
        while(driven < n){
            int curG = gas[startStation];
            int curS = startStation;
            while(driven < n && curG >= cost[curS]){
                curG -= cost[curS];
                driven++; curS = (curS+1)%n; 
                curG += gas[curS];
            }
            if(driven == n) return startStation;
            else{
                if((curS+1)%n <= startStation) return -1;
                startStation = (curS+1)%n;
                driven = 0;
            }
        }
        return -1; // something is weird
    }
}; 