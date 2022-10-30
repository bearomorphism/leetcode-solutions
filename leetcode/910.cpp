class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = nums.back() - nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            ret = min(ret, max(nums.back() - k, nums[i] + k) - min(nums[0] + k, nums[i + 1] - k));
        }
        return ret;
    }
};