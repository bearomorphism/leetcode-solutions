class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        unordered_map<int, int> um;
        for (int i = v.size() - 1; i >= 0; i--) {
            um[v[i]] = i;
        }
        vector<int> ret;
        for (int n: nums) {
            ret.push_back(um[n]);
        }
        return ret;
    }
};