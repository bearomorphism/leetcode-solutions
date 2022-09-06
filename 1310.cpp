class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> dp({0});
        for (int i: arr) {
            dp.push_back(dp.back() ^ i);
        }
        vector<int> ret;
        for (auto &v: queries) {
            ret.push_back(dp[v[1] + 1] ^ dp[v[0]]);
        }
        return ret;
    }
};