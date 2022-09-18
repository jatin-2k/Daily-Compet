class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i=0, j=height.size()-1;
        int lm = 0, rm = 0, ans = 0;
        while(i<j){
            if(height[i] < lm)
                ans += lm - height[i];
            if(height[j] < rm)
                ans += rm - height[j];
            lm = max(height[i],lm);
            rm = max(height[j],rm);
            (height[i] < height[j]) ? i++ : j--;
        }
        return ans;
    }
};



