class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int, int>> v;
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> ret(row, vector<int>(col, -1));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    v.push_back({i, j});
                    ret[i][j] = 0;
                }
            }
        }
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int k = 1;
        while (!v.empty()) {
            vector<pair<int, int>> v2;
            for (auto &p: v) {
                for (int d = 0; d < 4; d++) {
                    int a = p.first + dx[d], b = p.second + dy[d];
                    if (0 <= min(a, b) && a < row && b < col && ret[a][b] == -1) {
                        ret[a][b] = k;
                        v2.push_back({a, b});
                    }
                }
            }
            k++;
            v = v2;
        }
        return ret;
    }
};