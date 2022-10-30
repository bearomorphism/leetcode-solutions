class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int cnt = 0;
        for (auto c : s)
        {
            if (c == letter)
            {
                cnt++;
            }
        }
        return cnt * 100 / s.length();
    }
};