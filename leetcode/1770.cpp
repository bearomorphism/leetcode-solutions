class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<int> dp(m + 1);
        for (int i = m - 1; i >= 0; i--) {
            vector<int> dp2(dp.begin(), dp.end());
            for (int j = i; j >= 0; j--) {
                dp[j] = max(
                    multipliers[i] * nums[j] + dp2[j + 1],
                    multipliers[i] * nums[n - 1 - (i - j)] + dp2[j]
                );
            }
        }
        return dp[0];
    }
};