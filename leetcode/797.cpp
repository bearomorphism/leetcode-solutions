class Solution {
private:
    void dfs(vector<vector<int>> &g, int s, vector<vector<int>> &ret, vector<int> &cur) {
        cur.push_back(s);
        if (s != g.size() - 1) {
            for (int t: g[s]) {
                dfs(g, t, ret, cur);
            }
        } else {
            ret.push_back(cur);
        }
        cur.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        vector<int> v;
        dfs(graph, 0, ret, v);
        return ret;
    }
};