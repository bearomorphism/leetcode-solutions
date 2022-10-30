class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k);
        int p = 0;
        cnt[0]++;
        int ret = 0;
        for (int num: nums) {
            p = ((num + p) % k + k) % k;
            ret += cnt[p];
            cnt[p]++;
        }
        return ret;
    }
};