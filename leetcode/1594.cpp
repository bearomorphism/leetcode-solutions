class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<long long>> lo(row, vector<long long>(col, 0)), hi(row, vector<long long>(col, 0));
        lo[0][0] = hi[0][0] = grid[0][0];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                long long hig = LONG_LONG_MIN, low = LONG_LONG_MAX;
                if (i == 0 && j == 0) hig = low = 1;
                if (i > 0) {
                    low = min(low, lo[i - 1][j]);
                    hig = max(hig, hi[i - 1][j]);
                }
                if (j > 0) {
                    low = min(low, lo[i][j - 1]);
                    hig = max(hig, hi[i][j - 1]);
                }
                hig *= grid[i][j];
                low *= grid[i][j];
                if (hig < low) swap(hig, low);
                lo[i][j] = low;
                hi[i][j] = hig;
            }
        }
        return max(-1LL, hi[row - 1][col - 1]) % 1000000007;
    }
};