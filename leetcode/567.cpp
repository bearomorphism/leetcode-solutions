class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size(), col = mat[0].size();
        int k = row * col;
        if (k != r * c) return mat;
        vector<vector<int>> result(r, vector<int>(c));
        for (int i = 0; i < k; i++) {
            result[i / c][i % c] = mat[i / col][i % col];
        }
        return result;
    }
};