class Solution {
public:
    int bin(vector<int>& piles, int l, int r, int h){
        if(l<=r){
            int mid = l + ((r-l)/2);
            if(timeToEat(piles,mid) > h) return bin(piles, mid+1, r, h);
            else return bin(piles, l, mid-1, h);
        }
        return l;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mx_ele = *max_element(piles.begin(), piles.end());
        if(h==n) return mx_ele;
        return bin(piles, 1, mx_ele, h);
    }
    
    int timeToEat(vector<int>& piles, double speed){
        int ans =0;
        for( int &pile: piles){
            ans += ceil(pile/speed);
        }
        return ans;
    }
};

