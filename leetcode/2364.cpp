class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long tmp = 0;
        for (int i = 0; i < n; i++) {
            int x = i - nums[i];
            tmp += cnt[x]++;
        }
        return (long long)n * (n - 1) / 2 - tmp;
    }
};