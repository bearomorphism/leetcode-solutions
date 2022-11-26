class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string cur;
        for (auto &w: words) {
            string s(w);
            sort(s.begin(), s.end());
            if (cur != s) {
                cur = s;
                result.push_back(w);
            }
        }
        return result;
    }
};