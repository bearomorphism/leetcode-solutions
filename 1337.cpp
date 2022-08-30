class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < mat.size(); i++) {
            v.push_back({accumulate(mat[i].begin(), mat[i].end(), 0), i});
        }
        sort(v.begin(), v.end());
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(v[i].second);
        }
        return ret;
    }
};