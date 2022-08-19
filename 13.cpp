class Solution
{
public:
    int romanToInt(string s)
    {
        int val[256];
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int ans = 0, idx = 0;
        while (idx < s.length())
        {
            if (idx + 1 < s.length() && val[s[idx]] < val[s[idx + 1]])
            {
                ans += val[s[idx + 1]] - val[s[idx]];
                idx += 2;
            }
            else
            {
                ans += val[s[idx]];
                idx++;
            }
        }
        return ans;
    }
};