class Solution {
public:
    int numDecodings(const string &s) {
        constexpr int mod{static_cast<int>(1e9 + 7)};
        vector<long long> dp(s.length() + 2);
        int n = s.length();
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            dp[i] %= mod;
            if (s[i] == '*') dp[i + 1] += dp[i] * 9;
            else if (s[i] != '0') dp[i + 1] += dp[i];

            if (s[i] == '*' || s[i] == '1') {
                if (s[i + 1] == '*') dp[i + 2] += dp[i] * 9;
                else dp[i + 2] += dp[i];
            }
            if (s[i] == '*' || s[i] == '2') {
                if (s[i + 1] == '*') dp[i + 2] += dp[i] * 6;
                else if ('0' <= s[i + 1] && s[i + 1] <= '6') dp[i + 2] +=  dp[i];
            }
        }
        return dp[n] % mod;
    }
};