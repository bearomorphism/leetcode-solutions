class Solution
{
public:
    string stringSum(string s)
    {
        int n = 0;
        for (auto &c : s)
        {
            n += c - '0';
        }
        return to_string(n);
    }
    string digitSum(string s, int k)
    {
        while (s.length() > k)
        {
            string t;
            for (int i = 0; i < s.length(); i += k)
            {
                t += stringSum(s.substr(i, min(i + k, (int)s.length()) - i));
            }
            s = t;
        }
        return s;
    }
};