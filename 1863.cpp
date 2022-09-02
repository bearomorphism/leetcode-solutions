class Solution {
private:
    void dfs(vector<int> &nums, int idx, int cur, int &ret) {
        if (idx == nums.size()) {
            ret += cur;
            return;
        }
        dfs(nums, idx + 1, cur, ret);
        dfs(nums, idx + 1, cur ^ nums[idx], ret);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ret = 0;
        dfs(nums, 0, 0, ret);
        return ret;
    }
};