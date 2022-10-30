class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<long long> dp(1100);
        vector<long long> dp2(1100);
        dp[0] = 1;
        while (n--) {
            fill(dp2.begin(), dp2.end(), 0);
            for (int j = target; j >= 0; j--) {
                for (int i = 1; i <= k; i++) {
                    dp2[j + i] += dp[j];
                }
            }

            for (auto &i: dp2) {
                i %= 1000000007;
            }
            swap(dp, dp2);
        }
        return dp[target];
    }
};