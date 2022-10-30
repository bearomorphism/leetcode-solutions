class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ret;
        int row = land.size(), col = land[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (land[i][j] == 1) {
                    int r = i, c = j;
                    while (r < row && land[r][c] == 1) r++;
                    r--;
                    while (c < col && land[r][c] == 1) c++;
                    c--;
                    for (int u = i; u <= r; u++) {
                        for (int v = j; v <= c; v++) {
                            land[u][v] = 0;
                        }
                    }
                    ret.push_back({i, j, r, c});
                }
            }
        }
        return ret;
    }
};