class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> v;
        v.push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) v.push_back(i);
        }
        v.push_back(nums.size());
        int ret = 0;
        for (int i = 2; i < v.size(); i++) {
            ret = max(ret, v[i] - v[i - 2] - 2);
        }
        if (ret == 0 && nums[0] == 1) return nums.size() - 1;
        return ret;
    }
};