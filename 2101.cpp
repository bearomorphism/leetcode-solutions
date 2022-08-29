class Solution {
private:
    void dfs(vector<vector<int>> &g, int idx, vector<bool>& vis, int& ret) {
        vis[idx] = true;
        ret++;
        for (int j: g[idx]) {
            if (!vis[j]) {
                dfs(g, j, vis, ret);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> g(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long a = bombs[i][0] - bombs[j][0];
                long long b = bombs[i][1] - bombs[j][1];
                if (i != j && a * a + b * b <= (long long)bombs[i][2] * bombs[i][2]) {
                    g[i].push_back(j);
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int m = 0;
            vector<bool> vis(n, false);
            dfs(g, i, vis, m);
            ret = max(ret, m);
        }
        return ret;
    }
};