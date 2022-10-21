class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n + 1);
        v[0] = true;
        v[2] = nums[1] == nums[0];
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i - 1] && v[i - 1]
               || (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2] || nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1) && v[i - 2]) {
                v[i + 1] = true;
            }
        }
        return v[n];
    }
};
