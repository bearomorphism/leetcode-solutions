class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int i = 0;
        while (i < k) {
            sum += nums[i];
            i++;
        }
        int m = sum;
        while (i < nums.size()) {
            sum += nums[i] - nums[i - k];
            i++;
            m = max(m, sum);
        }
        return (double)m / k;
    }
};