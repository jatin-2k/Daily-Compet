class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int i=0,j=n-1;
        while(i<j){
            int width = j-i;
            int waterH = min(height[i], height[j]);
            ans = max(ans, waterH*width);
            if(height[i] > height[j]) j--;
            else i++;
        }
        return ans;
    }
};