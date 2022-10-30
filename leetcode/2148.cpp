class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l < nums.size() && nums[l] == nums[0]) l++;
        while (r >= 0 && nums[r] == nums.back()) r--;
        return max(0, r - l + 1);
    }
};