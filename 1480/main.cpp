class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ret(1, nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            ret.push_back(ret[i - 1] + nums[i]);
        }
        return ret;
    }
};