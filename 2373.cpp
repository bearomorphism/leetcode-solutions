class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> result(row - 2, vector<int>(col - 2));
        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                int m = INT_MIN;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        m = max(m, grid[i + x][j + y]);
                    }
                }
                result[i - 1][j - 1] = m;
            }
        }
        return result;
    }
};