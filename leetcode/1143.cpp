class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        if (m < n) return longestCommonSubsequence(text2, text1);

        vector<int> dp1(n+1), dp2(n+1);
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp2[j + 1] = text1[i] == text2[j] ? dp1[j] + 1 : max(dp1[j + 1], dp2[j]);
                result = max(result, dp2[j + 1]);
            }
            dp1.swap(dp2);
            fill(dp2.begin(), dp2.end(), 0);
        }
        return result;
    }
};