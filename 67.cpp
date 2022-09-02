class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) swap(a, b);
        int n = b.length();
        int inc = 0;
        string s;
        for (int i = 0; i < n; i++) {
            int t = b[b.length() - i - 1] - '0' * 2 + a[a.length() - i - 1] + inc;
            if (t >= 2) {
                s.push_back('0' + t - 2);
                inc = 1;
            } else {
                s.push_back('0' + t);
                inc = 0;
            }
        }
        for (int i = n; i < a.length(); i++) {
            int t = a[a.length() - i - 1] + inc - '0';
            if (t >= 2) {
                s.push_back('0' + t - 2);
                inc = 1;
            } else {
                s.push_back('0' + t);
                inc = 0;
            }
        }
        if (inc) s.push_back('1');
        reverse(s.begin(), s.end());
        return s;
    }
};