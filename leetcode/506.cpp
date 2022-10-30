class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>>v;
        for (int i = 0; i < score.size(); i++) {
            v.push_back({score[i], i});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector<string>ret(score.size());
        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                ret[v[i].second] = "Gold Medal";
            } else if (i == 1) {
                ret[v[i].second] = "Silver Medal";
            } else if (i == 2) {
                ret[v[i].second] = "Bronze Medal";
            } else {
                ret[v[i].second] = to_string(i + 1);
            }
        }
        return ret;
    }
};