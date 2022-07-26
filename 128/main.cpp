class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_set<int> u(nums.begin(), nums.end());
    int ans = 0;
    for (auto &i : u)
    {
      if (u.find(i - 1) == u.end())
      {
        int j = i + 1;
        while (u.find(j) != u.end())
          j++;
        ans = max(ans, j - i);
      }
    }
    return ans;
  }
};