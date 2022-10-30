class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v(m, 0);
        for (int i = 0; i < m; i++) {
            v[i] = i + 1;
        }
        vector<int> ret;
        for (int q: queries) {
            int j = 0;
            while (v[j] != q) j++;
            ret.push_back(j);
            for (int k = j; k > 0; k--) {
                v[k] = v[k - 1];
            }
            v[0] = q;
        }
        return ret;
    }
};