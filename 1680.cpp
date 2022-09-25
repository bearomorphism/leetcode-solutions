class Solution {
public:
    int concatenatedBinary(int n) {
        long long result = 0, mod = (long long)1e9 + 7;
        for (int i = 1; i <= n; i++) {
            int offset = 32 - __builtin_clz(i);
            result = ((result << offset) | i) % mod;
        }
        return result;
    }
};