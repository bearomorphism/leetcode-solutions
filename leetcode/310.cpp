class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> g(n);
        for (auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<int> degrees(n);
        vector<int> leaves, ret;
        for (int i = 0; i < n; i++) {
            degrees[i] = g[i].size();
            if (degrees[i] == 1) leaves.push_back(i);
        }
        while (!leaves.empty()) {
            ret = leaves;
            leaves.clear();
            for (int i: ret) {
                degrees[i]--;
                for (int j: g[i]) {
                    degrees[j]--;
                    if (degrees[j] == 1) leaves.push_back(j);
                }
            }
        }
        return ret;
    }
};