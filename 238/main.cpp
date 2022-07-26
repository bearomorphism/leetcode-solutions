class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int l = 1, r = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = l;
            l *= nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= r;
            r *= nums[i];
        }
        return res;
    }
};