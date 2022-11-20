class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> vis(s.length() + 1);
        vis[0] = true;
        for (int i = 0; i < s.length(); i++) {
            if (vis[i]) {
                for (auto &w: wordDict) {
                    int j = 0;
                    bool flag = true;
                    for (char c: w) {
                        if (s[i + j] != c) {
                            flag = false;
                            break;
                        }
                        j++;
                    }
                    if (flag) vis[i + w.length()] = true;
                }
            }
        }
        return vis.back();
    }
};