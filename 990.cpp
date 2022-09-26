class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        v = vector<int>(26);
        for (int i = 0; i < 26; i++) {
            v[i] = i;
        }
        for (auto &s: equations) {
            if (s[1] == '=') {
                int a = s[0] - 'a', b = s[3] - 'a';
                int roota = findDSU(a), rootb = findDSU(b);
                v[roota] = rootb;
            }
        }
        for (auto &s: equations) {
            if (s[1] == '!' && findDSU(s[0] - 'a') == findDSU(s[3] - 'a'))
                return false;
        }
        return true;
    }
private:
    vector<int> v;
    int findDSU(int x) {
        if (x == v[x]) return x;
        return v[x] = findDSU(v[x]);
    }
};