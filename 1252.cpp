class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<bool> r(m), c(n);
        for (auto &v: indices) {
            r[v[0]] = !r[v[0]];
            c[v[1]] = !c[v[1]];
        }
        int rn = 0, cn = 0;
        for (int i = 0; i < m; i++) {
            if (r[i]) rn++;
        }
        for (int i = 0; i < n; i++) {
            if (c[i]) cn++;
        }
        return rn * n + cn * m - 2 * rn * cn;
    }
};