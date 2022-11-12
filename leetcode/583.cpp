class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int result = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = 1 + dp[i][j];
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
                result = max(result, dp[i+1][j+1]);
            }
        }
        return m + n - result * 2;
    }
};