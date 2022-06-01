class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        vector<int> v(nums);
        while (v.size() > 1)
        {
            vector<int> u;
            for (int i = 0; i < v.size() - 1; i++)
            {
                u.push_back((v[i] + v[i + 1]) % 10);
            }
            v = u;
        }
        return v[0];
    }
};