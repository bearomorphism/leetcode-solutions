class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1];
            if (Find(x) == Find(y)) return {x, y};
            Union(x, y);
        }
        return {};
    }
private:
    vector<int> parent;
    int Find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = Find(parent[x]);
    }
    void Union(int x, int y) {
        parent[Find(x)] = Find(y);
    }
};