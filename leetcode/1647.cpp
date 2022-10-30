class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for (char &c: s) {
            cnt[c - 'a']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        unordered_set<int> us;
        int ret = 0;
        for (int i: cnt) {
            while (i > 0 && us.count(i)) {
                i--;
                ret++;
            }
            if (i) us.insert(i);
        }
        return ret;
    }
};