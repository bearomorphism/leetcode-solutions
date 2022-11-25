class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int g = __gcd(n, m);
        string result = str1.substr(0, g);
        for (int i = 0; i < n; i += g) {
            if (result != str1.substr(i, g)) return "";
        }
        for (int i = 0; i < m; i += g) {
            if (result != str2.substr(i, g)) return "";
        }
        return result;
    }
};