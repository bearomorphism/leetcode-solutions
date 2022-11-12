class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ret = 0, n = 8;
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x0, y0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'R') {
                    x0 = i;
                    y0 = j;
                    break;
                }
            }
        }
        for (int d = 0; d < 4; d++) {
            int x = x0, y = y0;
            while (1) {
                x += dx[d];
                y += dy[d];
                if (min(x, y) >= 0 && x < n && y < n) {
                    if (board[x][y] == 'B')
                        break;
                    else if (board[x][y] == 'p') {
                        ret++;
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        return ret;
    }
};