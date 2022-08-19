class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int m = 0, i = 0;
        while (i <= m)
        {
            m = max(m, i + nums[i]);
            i++;
            if (m >= nums.size() - 1)
                return true;
        }
        return false;
    }
};