class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (int i: nums) {
            um[i]++;
        }
        int ret = 0;
        for (auto &i: um) {
            if (k == 0 && i.second > 1 || k != 0 && um.find(i.first + k) != um.end()) ret++;
        }
        return ret;
    }
};