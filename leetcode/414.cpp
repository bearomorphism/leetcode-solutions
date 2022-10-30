class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());
        int n = nums.size();
        return n >= 3 ? nums[n - 3] : nums.back();
    }
};