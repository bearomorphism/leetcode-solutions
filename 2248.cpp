class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_set<int> us(nums[0].begin(), nums[0].end());
        for (int i = 1; i < nums.size(); i++) {
            unordered_set<int> b;
            for (int a: nums[i]) {
                if (us.find(a) != us.end()) b.insert(a);
            }
            us = b;
        }
        vector<int> ret(us.begin(), us.end());
        sort(ret.begin(), ret.end());
        return ret;
    }
};