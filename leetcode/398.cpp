class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            um_[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        vector<int> &t = um_[target];
        return t[rand() % t.size()];
    }
private:
    unordered_map<int, vector<int>> um_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */