class Solution {
public:
    long long maxRunTime(int pcs, vector<int>& juice) {
        sort(juice.begin(), juice.end());
        int n = juice.size();
        long long extra = 0, usedJuice = 0;
        for(int i=0; i<n-pcs; i++) extra += juice[i];
        
        for(int i=n-pcs, usedBatts = 1 ; i<n; i++, usedBatts++){
            usedJuice += juice[i];
            if(i+1 < n && (long long)juice[i+1]*usedBatts-usedJuice > extra) 
                return (usedJuice + extra)/usedBatts;
        }
        return (usedJuice + extra)/pcs;
    }
};

//https://leetcode.com/problems/maximum-running-time-of-n-computers/discuss/1693324/C%2B%2BJavaPython-Simple-Solution-with-Explanation