class Solution {
private:
    int ans, m;
    vector<bool> vis;
    void dfs(int idx) {
        if (idx == 0) {
            ans++;
            return;
        }
        for (int i = 1; i <= m; i++) {
            if (!vis[i] && (i % idx == 0 || idx % i == 0)) {
                vis[i] = true;
                dfs(idx - 1);
                vis[i] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        m = n;
        ans = 0;
        vis = vector<bool>(m);
        dfs(n);
        return ans;
    }
};