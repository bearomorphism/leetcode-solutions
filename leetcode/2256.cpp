class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int i: nums) {
            total += i;
        }
        long long sum = 0;
        int ret = -1;
        long long m = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            sum += (long long)nums[i];
            long long tmp = abs((sum / (i + 1)) - (i == n - 1 ? 0 : (total - sum) / (n - i - 1)));
            if (tmp < m) {
                m = tmp;
                ret = i;
            }
        }
        return ret;
    }
};