class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int cur = 0, total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cur += i * nums[i];
            total += nums[i];
        }
        int result = cur;
        for (int i = n - 1; i >= 0; i--) {
            cur = cur + total - nums[i] * n;
            result = max(result, cur);
        }
        return result;
    }
};