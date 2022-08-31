class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, prod = 1;
        int ret = 0;
        int n = nums.size();
        while (l < n) {
            while (r < n && prod * nums[r] < k) {
                prod *= nums[r];
                r++;
            }
            ret += r - l;
            if (prod != 1) {
                prod /= nums[l];
            }
            l++;
            r = max(r, l);
        }
        return ret;
    }
};