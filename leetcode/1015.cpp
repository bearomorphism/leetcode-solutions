class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<bool> vis(k);
        int cur = 1, ret = 1;
        int x;
        while (x = cur % k) {
            if (vis[x]) return -1;
            vis[x] = true;
            ret++;
            cur = x * 10 + 1;
        }
        return ret;
    }
};