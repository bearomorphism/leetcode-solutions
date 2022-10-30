class Solution {
private:
    int dfs(vector<vector<int>>& g, int idx, vector<bool>& vis) {
        vis[idx] = true;
        int ret = 1;
        for (int i: g[idx]) {
            if (!vis[i]) {
                ret += dfs(g, i, vis);
            }
        }
        return ret;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> cnt;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt.push_back(dfs(g, i, vis));
            }
        }
        long long sum = accumulate(cnt.begin(), cnt.end(), 0);
        long long ret = 0;
        for (int c: cnt) {
            sum -= c;
            ret += c * sum;
        }
        return ret;
    }
};