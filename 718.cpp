class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), result = 0;
        vector<int> dp(m + 1), prev_dp(m + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[j] = nums1[i - 1] == nums2[j - 1] ? prev_dp[j - 1] + 1 : 0;
                result = max(result, dp[j]);
            }
            dp.swap(prev_dp);
        }
        return result;
    }
};