class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<int>v({a, b, c});
        string s;
        while (1) {
            int idx = -1;
            int ma = -1;
            for (int i = 0; i < 3; i++) {
                if (v[i] > ma && (s.empty() || s.back() != (char)(i + 'a'))) {
                    ma = v[i];
                    idx = i;
                }
            }
            int m = *max_element(v.begin(), v.end());
            int n = 2;
            if (m != ma) {
                n = 1;
            }
            n = min(n, v[idx]);
            if (n == 0) return s;
            for (int i = 0; i < n; i++) {
                s += (char)(idx + 'a');
                v[idx]--;
            }
        }
    }
};