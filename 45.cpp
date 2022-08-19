#include <bits/stdc++.h>

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), INT_MAX - 1);
        dp[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            int m = min(nums[i], (int)nums.size() - i - 1);
            for (int j = 1; j <= m; j++)
            {
                dp[i] = min(dp[i], 1 + dp[i + j]);
            }
        }
        return dp[0];
    }
};
