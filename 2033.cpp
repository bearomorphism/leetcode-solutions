class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto &a: grid) {
            for (auto &b: a) {
                v.push_back(b);
            }
        }
        sort(v.begin(), v.end());
        int m = v[v.size() / 2];
        int ret = 0;
        for (int i: v) {
            int u = abs(i - m);
            if (u % x) return -1;
            ret += u / x;
        }
        return ret;
    }
};
