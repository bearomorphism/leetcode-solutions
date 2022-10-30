class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int m = queries.size(), n = dictionary.size();
        vector<string> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (helper(queries[i], dictionary[j])) {
                    result.push_back(queries[i]);
                    break;
                }
            }
        }
        return result;
    }
private:
    bool helper(string &a, string &b) {
        int cnt = 0;
        int n = a.length();
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                cnt++;
                if (cnt > 2) return false;
            }
        }
        return true;
    }
};