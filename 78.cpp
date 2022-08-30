class Solution {
private:
    void dfs(vector<int> &nums, int idx, vector<int> &cur, vector<vector<int>> &ret) {
        if (idx == nums.size()) {
            ret.push_back(cur);
            return;
        }
        dfs(nums, idx + 1, cur, ret);
        cur.push_back(nums[idx]);
        dfs(nums, idx + 1, cur, ret);
        cur.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ret;
        dfs(nums, 0, cur, ret);
        return ret;
    }
};