class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y;
        int ret = 0;
        while (t) {
            ret += (t & 1);
            t >>= 1;
        }
        return ret;
    }
};