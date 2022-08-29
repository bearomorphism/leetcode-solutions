class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (nums.size() == 1 && (k & 1)) return -1;
        if (k > nums.size()) return *max_element(nums.begin(), nums.end());
        if (k == nums.size()) return *max_element(nums.begin(), prev(nums.end()));
        int ret = nums[k];
        for (int i = 0; i < k - 1; i++) {
            ret = max(ret, nums[i]);
        }
        return ret;
    }
};