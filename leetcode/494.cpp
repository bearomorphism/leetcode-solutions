class Solution {
private:
    void dfs(vector<int> &nums, int idx, int target, int &ret) {
        if (idx == nums.size()) {
            if (target == 0) ret++;
            return;
        }
        dfs(nums, idx + 1, target + nums[idx], ret);
        dfs(nums, idx + 1, target - nums[idx], ret);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ret = 0;
        dfs(nums, 0, target, ret);
        return ret;
    }
};