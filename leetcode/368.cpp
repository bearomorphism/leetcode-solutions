class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1); // longest if ends at i
        vector<int> pre(n, -1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    int t = dp[j] + 1;
                    if (t > dp[i]) {
                        dp[i] = t;
                        pre[i] = j;
                    }
                }
            }
        }
        vector<int> ret;
        int x = max_element(dp.begin(), dp.end()) - dp.begin();
        while (x != -1) {
            ret.push_back(nums[x]);
            x = pre[x];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};