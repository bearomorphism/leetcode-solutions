class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, bool> um;
        int result = 0;
        for (char c: s) {
            if (um[c]) result += 2;
            um[c] = !um[c];
        }
        for (auto it: um) {
            if (it.second) return result + 1;
        }
        return result;
    }
};