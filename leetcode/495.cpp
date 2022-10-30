class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int res = 0;
        for (int i = 0; i < timeSeries.size(); i++)
        {
            if (i == timeSeries.size() - 1)
            {
                res += duration;
            }
            else
            {
                res += min(duration, timeSeries[i + 1] - timeSeries[i]);
            }
        }
        return res;
    }
};