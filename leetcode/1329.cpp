class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        for (int i = row - 1; i >= 0; i--) {
            vector<int> v;
            int x = 0;
            while (i + x < row && x < col) {
                v.push_back(mat[i + x][x]);
                x++;
            }
            sort(v.begin(), v.end());
            x = 0;
            while (i + x < row && x < col) {
                mat[i + x][x] = v[x];
                x++;
            }
        }
        for (int j = 1; j < col; j++) {
            vector<int> v;
            int x = 0;
            while (x < row && j + x < col) {
                v.push_back(mat[x][j + x]);
                x++;
            }
            sort(v.begin(), v.end());
            x = 0;
            while (x < row && j + x < col) {
                mat[x][j + x] = v[x];
                x++;
            }
        }
        return mat;
    }
};