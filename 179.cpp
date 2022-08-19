class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(), v.end(), [](string a, string b)
             { return (a + b) > (b + a); });
        string res;
        for (auto &s : v)
        {
            res += s;
        }
        int idx = 0;
        while (idx < nums.size() - 1 && res[idx] == '0')
        {
            idx++;
        }
        return res.substr(idx);
    }
};