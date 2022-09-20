class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ans = image;
        row = ans.size(), col = ans[0].size(), color_ = color, target = ans[sr][sc];

        if (color_ != target) dfs(sr, sc);
        return ans;
    }
private:
    vector<vector<int>> ans;
    int row, col, color_, target;
    void dfs(int i, int j) {
        static int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        ans[i][j] = color_;
        for (int d = 0; d < 4; d++) {
            int u = i + dx[d], v = j + dy[d];
            if (0 <= min(u, v) && u < row && v < col && ans[u][v] == target) {
                dfs(u, v);
            }
        }
    }
};