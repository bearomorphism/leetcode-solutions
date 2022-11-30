class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 1, cur = 1, last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > last) {
                result = max(result, ++cur);
            } else {
                cur = 1;
            }
            last = nums[i];
        }
        return result;
    }
};