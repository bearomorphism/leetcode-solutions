class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        vector<int> ret;
        while (k) {
            ret.push_back(v[n - k].second);
            k--;
        }
        sort(ret.begin(), ret.end());
        for (int &r: ret) {
            r = nums[r];
        }
        return ret;
    }
};