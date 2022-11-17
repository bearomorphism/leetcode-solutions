class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> cur;
        auto dfs = [&](int last, int target, auto &&dfs) -> void {
            if (target == 0) {
                if (cur.size() == k)
                    result.push_back(cur);
                return;
            }
            for (int i = last + 1; i <= 9; i++) {
                int x = target - i;
                if (x >= 0) {
                    cur.push_back(i);
                    dfs(i, x, dfs);
                    cur.pop_back();
                }
            }
        };
        dfs(0, n, dfs);
        return result;
    }
};