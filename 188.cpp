class Solution {
public:
    int solve(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        for (int i = 1; i < n; i++) {
            profit += max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) return solve(prices);
        int result = 0;
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            int tmpMax = -prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + tmpMax);
                tmpMax = max(tmpMax, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};