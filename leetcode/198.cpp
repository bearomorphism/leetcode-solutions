class Solution
{
public:
  int rob(vector<int> &nums)
  {
    if (nums.size() <= 2) return *max_element(nums.begin(), nums.end());
    if (nums.size() == 3) return max(nums[0] + nums[2], nums[1]);
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[2] + nums[0];
    for (int i = 3; i < nums.size(); i++)
    {
      dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
    }
    return max(dp[nums.size() - 1], dp[nums.size() - 2]);
  }
};