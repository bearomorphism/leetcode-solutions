class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> cnt(100005);
        for (int i: nums) {
            cnt[i]++;
        }
        int result = 0, cur = 0;
        for (int i = 0; i < 100005; i++) {
            if (cur > 0 && cnt[i] == 0) cur--;
            cur += max(0, cnt[i] - 1);
            result += cur;
        }
        result += (cur - 1) * cur / 2;
        return result;
    }
};