class Solution {
public:
    string reorganizeString(string s) {
        vector<int>cnt(26);
        for (char c: s) {
            cnt[c - 'a']++;
        }
        int n = s.length();
        string ret;
        int pre = -1;
        while (n > 0) {
            int fir = -1, sec = -1, fir_idx = -1, sec_idx = -1;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > fir) {
                    sec = fir;
                    sec_idx = fir_idx;
                    fir = cnt[i];
                    fir_idx = i;
                } else if (cnt[i] > sec) {
                    sec = cnt[i];
                    sec_idx = i;
                }
            }
            int idx = fir_idx;
            if (fir_idx == pre) {
                idx = sec_idx;
            }
            ret += (char)(idx + 'a');
            if (cnt[idx] == 0) return "";
            cnt[idx]--;
            pre = idx;
            n--;
        }
        return ret;
    }
};