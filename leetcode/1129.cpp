class Solution {
private:
    vector<int> bfs(int n, vector<vector<vector<int>>> edges, int f) {
        vector<vector<int>> ans(2, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        ans[0][0] = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int s = p.first, l = p.second;
            int x = (f + l) & 1;
            for (int v: edges[x][s]) {
                if (ans[1 - x][v] == -1) {
                    ans[1 - x][v] = l + 1;
                    q.push({v, l + 1});
                }
            }
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (ans[0][i] != -1 && ans[1][i] != -1) ret.push_back(min(ans[0][i], ans[1][i]));
            else ret.push_back(max(ans[0][i], ans[1][i]));
        }
        return ret;
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> edges(2, vector<vector<int>>(n, vector<int>()));
        for (auto& edge : redEdges) {
            edges[0][edge[0]].push_back(edge[1]);
        }
        for (auto& edge : blueEdges) {
            edges[1][edge[0]].push_back(edge[1]);
        }
        vector<int> v1 = bfs(n, edges, 0), v2 = bfs(n, edges, 1);
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (v1[i] != -1 && v2[i] != -1) ret.push_back(min(v1[i], v2[i]));
            else ret.push_back(max(v1[i], v2[i]));
        }
        return ret;
    }
};