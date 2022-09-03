class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        for (int i = 1; i <= n; i++) {
            ret[i] = ret[i / 2] + (i & 1);
        }
        return ret;
    }
};