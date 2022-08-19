class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < colors.length() - 1; i++)
        {
            if (colors[i] == colors[i + 1])
            {
                cnt++;
            }
            else
            {
                ans += max(cnt - 1, 0) * (colors[i] == 'A' ? 1 : -1);
                cnt = 0;
            }
        }
        ans += max(cnt - 1, 0) * (colors.back() == 'A' ? 1 : -1);
        return ans > 0;
    }
};