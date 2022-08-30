class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;
        for (int i: nums) total += i;
        long long sum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            sum += nums[i];
            if (sum * 2 >= total) ret++;
        }
        return ret;
    }
};