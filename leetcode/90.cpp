class Solution {
    void dfs(vector<vector<int>> &cnt, vector<vector<int>> &ret, vector<int> &cur, int idx) {
        if (idx == cnt.size()) {
            ret.push_back(cur);
            return;
        }
        dfs(cnt, ret, cur, idx + 1);
        if (cnt[idx][1] > 0) {
            cnt[idx][1]--;
            cur.push_back(cnt[idx][0]);
            dfs(cnt, ret, cur, idx);
            cur.pop_back();
            cnt[idx][1]++;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int i: nums) {
            um[i]++;
        }
        vector<vector<int>> cnt;
        for (auto &it: um) {
            cnt.push_back({it.first, it.second});
        }
        vector<int> cur;
        vector<vector<int>> ret;
        dfs(cnt, ret, cur, 0);
        return ret;
    }
};