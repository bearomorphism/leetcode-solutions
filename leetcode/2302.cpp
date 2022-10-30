class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ret = 0, cur = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, i);
            while (r < n && (cur + nums[r]) * (r - i + 1) < k) {
                cur += nums[r];
                r++;
            }
            ret += r - i;
            cur = max(0LL, cur - nums[i]);
        }
        return ret;
    }
};