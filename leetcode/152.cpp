class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> maxv(n, 0), minv(n, 0);
        maxv[0] = minv[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxv[i] = minv[i] = nums[i];
            long long a = nums[i] * maxv[i - 1], b = nums[i] * minv[i - 1];
            if (a > b) swap(a, b);
            minv[i] = min(minv[i], a);
            maxv[i] = max(maxv[i], b);
        }
        return *max_element(maxv.begin(), maxv.end());
    }
};