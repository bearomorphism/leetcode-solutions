class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            long long n_even = max(even, odd + nums[i]);
            long long n_odd = max(odd, even - nums[i]);
            even = n_even;
            odd = n_odd;
        }
        return even;
    }
};