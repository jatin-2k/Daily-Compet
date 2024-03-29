class Solution {
public:
    long long concatenatedBinary(int n, int l = 0) {
        long ans = 0, mod = 1e9+7;
        for (int i = 1; i <= n; ++i) {
            int len = 0;
            for (int j = i; j; j >>= 1, ++len);
            ans = ((ans << len) + i) % mod;
        }
        return ans;
    }
};