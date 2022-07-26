class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    if (nums.size() == 1)
    {
      return nums[0] == target ? 0 : -1;
    }
    int l, r;
    l = 0;
    r = nums.size() - 1;
    while (l < r)
    {
      int m = (l + r) / 2;
      if (nums[m] > nums[r])
        l = m + 1;
      else
        r = m;
    }
    int rot = l;
    cout << rot;
    l = 0;
    r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      int x = (m + rot) % nums.size();
      if (nums[x] == target) return x;
      else if (nums[x] > target) r = m - 1;
      else l = m + 1;
    }
    return -1;
  }
};