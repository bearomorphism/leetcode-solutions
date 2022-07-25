class Solution
{
public:
  int minimumCost(vector<int> &cost)
  {
    sort(cost.begin(), cost.end());
    reverse(cost.begin(), cost.end());
    int ret = 0;
    for (int i = 0; i < cost.size(); i++)
    {
      if ((i + 1) % 3)
        ret += cost[i];
    }
    return ret;
  }
};