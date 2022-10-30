class Solution {
private:
    void dfs(vector<int> &cnt, int idx, vector<int> &cur, int target, vector<vector<int>> &ret) {
        if (target == 0) {
            ret.push_back(cur);
        }
        if (idx > target) return;
        dfs(cnt, idx + 1, cur, target, ret);
        if (cnt[idx] > 0) {
            cnt[idx]--;
            cur.push_back(idx);
            dfs(cnt, idx, cur, target - idx, ret);
            cur.pop_back();
            cnt[idx]++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cnt(51);
        for (int c: candidates) {
            cnt[c]++;
        }
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(cnt, 1, cur, target, ret);
        return ret;
    }
};