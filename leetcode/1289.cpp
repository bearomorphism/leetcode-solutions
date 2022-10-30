class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> dp(matrix[0].begin(), matrix[0].end());
        for (int i = 1; i < row; i++) {
            vector<int> v(col);
            for (int j = 0; j < col; j++) {
                int best = INT_MAX;
                for (int k = 0; k < col; k++) {
                    if (k != j) best = min(best, dp[k]);
                }
                v[j] = best + matrix[i][j];
            }
            dp = v;
        }
        return *min_element(dp.begin(), dp.end());
    }
};