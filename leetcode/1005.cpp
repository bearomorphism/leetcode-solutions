class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for (int& num: nums) {
            if (num < 0 && k > 0) {
                num = -num;
                k--;
            }
        }
        if (k & 1) {
            auto m = min_element(nums.begin(), nums.end());
            *m = -*m;
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};