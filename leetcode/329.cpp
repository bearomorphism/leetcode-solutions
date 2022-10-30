class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        matrix_ = matrix;
        dp_ = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        int row = matrix.size(), col = matrix[0].size();
        int result = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result = max(result, dfs(i, j));
            }
        }
        return result;
    }
private:
    vector<vector<int>> dp_, matrix_;
    int dfs(int i, int j) {
        static const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        if (dp_[i][j] != -1) return dp_[i][j];

        int res = 0, cur = matrix_[i][j];
        for (int d = 0; d < 4; d++) {
            int u = i + dx[d], v = j + dy[d];
            if (0 <= min(u, v) && u < matrix_.size() && v < matrix_[0].size() && matrix_[u][v] < cur) {
                res = max(res, dfs(u, v));
            }
        }
        return dp_[i][j] = res + 1;
    }
};