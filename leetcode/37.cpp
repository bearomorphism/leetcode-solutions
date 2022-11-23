class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        ok_ = false;
        dfs(board, 0, 0);
    }
private:
    bool ok_;
    void dfs(vector<vector<char>> &board, int i, int j) {
        if (ok_) return;
        if (i == 9) {
            ok_ = true;
            return;
        }
        if (j == 9) {
            dfs(board, i + 1, 0);
            return;
        }
        if (board[i][j] == '.') {
            for (int d = 1; d <= 9; d++) {
                if (!ok_ && helper(board, i, j, d)) {
                    // cout << d << '\n';
                    board[i][j] = '0' + d;
                    dfs(board, i, j + 1);
                }
            }
            if (!ok_)
                board[i][j] = '.';
        } else {
            dfs(board, i, j + 1);
        }
    }
    bool helper(vector<vector<char>> &board, int i, int j, int d) {
        char c = d + '0';
        // cout << i << ' ' << j << ' ' << d << '\n';
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c || board[k][j] == c) return false;
        }
        int u = (i / 3) * 3, v = (j / 3) * 3;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (board[u + x][v + y] == c) return false;
            }
        }
        return true;
    }
};