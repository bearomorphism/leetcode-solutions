class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> cnt;
        for (const auto &v: matches) {
            int win = v[0], lose = v[1];
            if (cnt.find(win) == cnt.end()) {
                cnt[win] = 0;
            }
            cnt[lose]++;
        }

        vector<vector<int>> result(2);
        for (auto [key, value]: cnt) {
            if (value < 2) result[value].emplace_back(key);
        }
        for (int i = 0; i < 2; i++) {
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
};