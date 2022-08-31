class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> v;
        v.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (nums[i]) v.push_back(i);
        }
        v.push_back(n);
        int ret = 0;
        for (int i = 0; i + goal + 1 < v.size(); i++) {
            if (goal == 0) {
                int t = v[i + 1] - v[i];
                ret += t * (t - 1) / 2;
            } else {
                ret += (v[i + 1] - v[i]) * (v[i + goal + 1] - v[i + goal]);
            }
        }
        return ret;
    }
};