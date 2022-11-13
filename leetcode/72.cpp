class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if (m < n) return minDistance(word2, word1);

        vector<int> dp1(n + 1), dp2(n + 1);

        for (int i = 0; i < n; i++) {
            dp1[i + 1] = i + 1;
        }

        for (int i = 0; i < m; i++) {
            dp2[0] = i + 1;
            for (int j = 0; j < n; j++) {
                dp2[j + 1] = word1[i] == word2[j] ? dp1[j] : 1 + min({
                    dp1[j],
                    dp1[j + 1],
                    dp2[j]
                });
            }
            dp1.swap(dp2);
        }
        return dp1.back();
    }
};