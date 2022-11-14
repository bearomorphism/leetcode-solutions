class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<bool> cnt(10001);
        for (int i: nums) {
            if (cnt[i]) return i;
            cnt[i] = true;
        }
        return -1;
    }
};