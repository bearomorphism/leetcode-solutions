class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int hi = nums[0], r = -1;
        for (int i = 1; i < n; i++) {
            if (hi > nums[i]) {
                r = i;
            } else {
                hi = nums[i];
            }
        }
        int lo = nums.back(), l = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (lo < nums[i]) {
                l = i;
            } else {
                lo = nums[i];
            }
        }
        return r - l + 1;
    }
};