class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int mask = 0;
        for(int i=31; i>=0; i--){
            mask = mask | (1<<i); // 000 -> 100..00 -> 1100..00 -> 1110..0
            set<int> leftOfNums;
            for(auto i:nums){
                leftOfNums.insert(i & mask);
            }
            int temp = ans | (1<<i);
            for(auto a: leftOfNums){
                int b = a ^ temp;
                if(leftOfNums.find(b) != leftOfNums.end()){
                    ans = temp;
                }
            }
        }
        return ans;
    }
};