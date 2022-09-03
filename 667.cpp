class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret(n);
        int u = 0;
        for (int i = 1; i < n - k; i++) {
            ret[u++] = i;
        }
        for (int i = 0; i <= k; i++) {
            ret[u++] = (i & 1) ? (n - i / 2) : (n - k + i / 2);
        }
        return ret;
    }
};