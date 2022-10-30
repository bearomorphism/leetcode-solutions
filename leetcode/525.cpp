class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, vector<int>> um;
        int cnt = 0;
        um[0].push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 1 ? 1 : -1);
            um[cnt].push_back(i);
        }
        int ret = 0;
        for (auto it: um) {
            ret = max(ret, it.second.back() - it.second[0]);
        }
        return ret;
    }
};