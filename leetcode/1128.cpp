class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> cnt(100, 0);
        int ret = 0;
        for (auto &v: dominoes) {
            int x = v[0], y = v[1];
            if (x > y) swap(x, y);
            int tmp = x * 10 + y;
            ret += cnt[tmp];
            cnt[tmp]++;
        }
        return ret;
    }
};