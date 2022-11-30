class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        nums.emplace_back(INT_MAX);
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[i].first < dp[j].first + 1) {
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    } else if (dp[i].first == dp[j].first + 1) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
        }
        return dp.back().second;
    }
};