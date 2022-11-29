class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        vector<unordered_map<long long, int>> cnt(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long)nums[i] - (long long)nums[j];
                int sum = cnt[j].find(d) == cnt[j].end() ? 0 : cnt[j][d];
                cnt[i][d] += sum + 1;
                result += sum;
            }
        }
        return result;
    }
};