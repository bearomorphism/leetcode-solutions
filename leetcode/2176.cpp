class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<vector<int>> cnt(101, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]].push_back(i);
        }
        int ret = 0;
        for (auto &v: cnt) {
            for (int i = 0; i < v.size(); i++) {
                for (int j = i + 1; j < v.size(); j++) {
                    if (v[i] * v[j] % k == 0) ret++;
                }
            }
        }
        return ret;
    }
};