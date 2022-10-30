class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x, n = nums.size();
        int lo = 0, result = -1;
        if (target == 0) result = 0;
        for (int j = 0; j < n; j++) {
            target -= nums[j];
            while (target < 0 && lo < j) {
                target += nums[lo++];
            }
            if (target == 0) result = max(result, j - lo + 1);
        }
        if (result == -1) return -1;
        return n - result;
    }
};