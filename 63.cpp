class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int row = g.size(), col = g[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
        dp[0][1] = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!g[i][j])
                    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
            }
        }
        return dp[row][col];
    }
};