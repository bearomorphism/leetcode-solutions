class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char> v;
        for (char c: s) {
            if (isalpha(c)) v.push_back(c);
        }
        reverse(v.begin(), v.end());
        int k = 0;
        for (char c: v) {
            while (!isalpha(s[k])) k++;
            s[k] = c;
            k++;
        }
        return s;
    }
};