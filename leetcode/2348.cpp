class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int cnt = 0;
        long long ret = 0;
        for (int i: nums) {
            if (i == 0) {
                cnt++;
                ret += cnt;
            } else {
                cnt = 0;
            }
        }
        return ret;
    }
};