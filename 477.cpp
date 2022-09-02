class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0, n = nums.size();
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int j: nums) {
                cnt += (j >> i) & 1;
            }
            ret += cnt * (n - cnt);
        }
        return ret;
    }
};