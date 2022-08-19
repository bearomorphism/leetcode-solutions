class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    if (m == 1 || n == 1) return 1;
    m--;
    n--;
    if (m < n) swap(m, n);
    long long res = 1;
    int j = 1;
    for (int i = m + 1; i <= m + n; i++) {
      res *= i;
      res /= j;
      j++;
    }
    return (int)res;
  }
};