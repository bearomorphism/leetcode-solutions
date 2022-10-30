class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int tmp = nums[i] * nums[j];
                auto it = um.find(tmp);
                if (it == um.end()) um[tmp] = 0;
                um[tmp]++;
            }
        }
        int ret = 0;
        for (auto& it: um) {
            ret += it.second * (it.second - 1) * 4;
        }
        return ret;
    }
};