class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (!nums.size()) return {};
        vector<string> ret;
        int n = nums.size();
        int l = 0;
        auto helper = [&](int x) {
            string s = to_string(nums[l]);
            if (x - 1 != l) {
                s += "->" + to_string(nums[x - 1]);
            }
            ret.push_back(s);
        };
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] != nums[i] - 1) {
                helper(i);
                l = i;
            }
        }
        helper(n);
        return ret;
    }
};