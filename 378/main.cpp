class Solution
{
private:
  int search(vector<vector<int>> &matrix, int target)
  {
    int ret = 0;
    int i = matrix.size() - 1, j = 0;
    while (i >= 0)
    {
      while (j < matrix[i].size() && matrix[i][j] <= target)
      {
        j++;
      }
      ret += j;
      i--;
    }
    return ret;
  }

public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    int l = matrix[0][0], r = matrix.back().back() + 1;
    while (l < r)
    {
      int m = l + (r - l) / 2;
      if (search(matrix, m) < k)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};