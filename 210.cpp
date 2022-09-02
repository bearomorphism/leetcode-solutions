class Solution {
private:
    void dfs(int idx, vector<vector<int>> &g, vector<int> &vis, vector<int> &ret) {
        vis[idx] = 1;
        for (int i: g[idx]) {
            if (vis[i] == 1) return;
            if (vis[i] == 0) {
                dfs(i, g, vis, ret);
            }
        }
        vis[idx] = 2;
        ret.push_back(idx);
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> vis(n, 0);
        vector<int> ind(n);
        for (auto &v: prerequisites) {
            g[v[0]].push_back(v[1]);
            ind[v[1]]++;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) dfs(i, g, vis, ret);
        }
        if (ret.size() != n) return {};
        return ret;
    }
};