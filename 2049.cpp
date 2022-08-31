class Solution {
private:
    void dfs(vector<int> &sz, int idx, vector<vector<int>> &v) {
        sz[idx] = 1;
        for (int i: v[idx]) {
            if (sz[i] == -1) {
                dfs(sz, i, v);
                sz[idx] += sz[i];
            }
        }
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] >= 0) {
                v[parents[i]].push_back(i);
            }
        }
        vector<int> sz(n, -1);
        dfs(sz, 0, v);
        long long m = 0, ret = 0;
        for (int i = 0; i < n; i++) {
            long long a = max(1, sz[0] - sz[i]);
            long long b = v[i].size() > 0 ? sz[v[i][0]] : 1;
            long long c = v[i].size() > 1 ? sz[v[i][1]] : 1;
            long long x = a * b * c;
            if (m < x) {
                m = x;
                ret = 0;
            }
            if (m == x) {
                ret++;
            }
        }
        return ret;
    }
};