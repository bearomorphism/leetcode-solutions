class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 0;
        int ret = 0;
        int cnt = 0, diff;
        for (int i = 2; i < n; i++) {
            if (cnt == 0) {
                if (nums[i - 2] + nums[i] == 2 * nums[i - 1]) {
                    diff = nums[i] - nums[i - 1];
                    cnt++;
                }
            } else if (nums[i] - nums[i - 1] == diff) {
                cnt++;
            } else {
                cnt = 0;
            }
            ret += cnt;
        }
        return ret;
    }
};