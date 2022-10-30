class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && target > 0) {
                target -= nums[j++];
            }
            if (target <= 0) ans = min(ans, j - i);
            target += nums[i];
        }
        return ans == INT_MAX ? 0 : ans;
    }
};