class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int c: coins) {
            for (int i = 0; i + c <= amount; i++) {
                if (dp[i] != INT_MAX) dp[i + c] = min(dp[i + c], dp[i] + 1);
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};