class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int cur = 0;
        vector<bool> ret;
        for (int i: nums) {
            cur = ((cur << 1) | i) % 5;
            ret.push_back(cur == 0);
        }
        return ret;
    }
};