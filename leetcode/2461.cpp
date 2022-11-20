class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0, sum = 0;
        vector<int> cnt(100001);
        int cnt2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (++cnt[nums[i]] == 2) {
                cnt2++;
            }
            if (i >= k) {
                sum -= nums[i - k];
                if (--cnt[nums[i - k]] == 1) {
                    cnt2--;
                }
            }
            if (i >= k - 1 && !cnt2) {
                result = max(result, sum);
            }
        }
        return result;
    }
};