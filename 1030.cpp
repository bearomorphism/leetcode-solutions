class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ret;
        ret.push_back({rCenter, cCenter});
        int n = max(rCenter, rows - rCenter) + max(cCenter, cols - cCenter);
        for (int r = 1; r <= n; r++) {
            for (int i = -r; i <= r; i++) {
                int j = r - abs(i);
                int x = rCenter + i, y = cCenter + j;
                if (0 <= min(x, y) && x < rows && y < cols) {
                    ret.push_back({x, y});
                }
                if (j != 0) {
                    y = cCenter - j;
                    if (0 <= min(x, y) && x < rows && y < cols) {
                        ret.push_back({x, y});
                    }
                }
            }
        }
        return ret;
    }
};