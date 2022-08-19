class Solution
{
public:
  int hIndex(vector<int> &citations)
  {
    int l = 0, r = citations.size() - 1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (citations[mid] < citations.size() - mid)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return citations.size() - l;
  }
};