class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        long long dist = -goal;
        for (auto &i : nums)
            dist += i;
        dist = abs(dist);
        return (dist / limit) + (dist % limit == 0 ? 0 : 1);
    }
};