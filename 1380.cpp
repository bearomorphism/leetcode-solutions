class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<bool> v(100005, false);
        for (int i = 0; i < row; i++) {
            int m = INT_MAX;
            for (int j = 0; j < col; j++) {
                m = min(m, matrix[i][j]);
            }
            v[m] = true;
        }
        vector<int> ret;
        for (int j = 0; j < col; j++) {
            int m = 0;
            for (int i = 0; i < row; i++) {
                m = max(m, matrix[i][j]);
            }
            if (v[m]) ret.push_back(m);
        }
        return ret;
    }
};