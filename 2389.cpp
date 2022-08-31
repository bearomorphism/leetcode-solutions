class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        v.push_back(0);
        for (int i: nums) {
            v.push_back(v.back() + i);
        }
        vector<int> ret;
        for (int q: queries) {
            auto it = upper_bound(v.begin(), v.end(), q);
            ret.push_back((it - v.begin()) - 1);
        }
        return ret;
    }
};