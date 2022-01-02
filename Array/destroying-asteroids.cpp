class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long nmass = mass;
        for(int i=0; i<n; i++){
            if(asteroids[i] <= nmass) nmass += asteroids[i];
            else return false;
        }
        return true;
    }
};