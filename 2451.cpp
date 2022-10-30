class Solution {
public:
    string oddString(vector<string>& words) {
        vector<pair<string, int>> v;
        for (auto s: words) {
            int diff = s[0] - 'a';
            for (char &c: s) {
                c -= diff;
            }
            v.push_back({s, diff});
        }
        sort(v.begin(), v.end());
        if (v[0].first == v[1].first) return revert(v.back().first, v.back().second);
        return revert(v[0].first, v[0].second);
    }
private:
    string revert(string s, int i) {
        string ret = "";
        for (char c: s) {
            ret += c + i;
        }
        return ret;
    }
};