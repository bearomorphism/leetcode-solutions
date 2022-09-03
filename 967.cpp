class Solution {
private:
    vector<int> ans;
    string s;
    void dfs(int n, int k) {
        if (n == 0) {
            ans.push_back(stoi(s));
            return;
        }
        vector<int> v({k, -k});
        if (k == 0) v.pop_back();
        for (int i: v) {
            char t = s.back() + i;
            if (isdigit(t)) {
                s.push_back(t);
                dfs(n - 1, k);
                s.pop_back();
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        ans.clear();
        for (char i = '1'; i <= '9'; i++) {
            s.clear();
            s.push_back(i);
            dfs(n - 1, k);
        }
        return ans;
    }
};