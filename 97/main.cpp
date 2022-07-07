class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        dp[0][0] = 0;
        for (int i = 0; i <= s1.length(); i++)
        {
            for (int j = 0; j <= s2.length(); j++)
            {
                int cur = dp[i][j];
                if (cur != -1)
                {
                    if (i != s1.length() && s1[i] == s3[cur])
                    {
                        dp[i + 1][j] = cur + 1;
                    }
                    if (j != s2.length() && s2[j] == s3[cur])
                    {
                        dp[i][j + 1] = cur + 1;
                    }
                }
            }
        }
        return dp[s1.length()][s2.length()] != -1;
    }
};