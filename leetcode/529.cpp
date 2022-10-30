class Solution {
private:
    void dfs(vector<vector<char>> &board, int r, int c) {
        int row = board.size(), col = board[0].size();
        int cnt = 0;
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                int u = r + x, v = c + y;
                if (0 <= u && 0 <= v && u < row && v < col && board[u][v] == 'M') cnt++;
            }
        }
        if (cnt == 0) {
            board[r][c] = 'B';
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int u = r + x, v = c + y;
                    if (0 <= u && 0 <= v && u < row && v < col && board[u][v] == 'E') dfs(board, u, v);
                }
            }
        } else {
            board[r][c] = '0' + cnt;
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        dfs(board, r, c);
        return board;
    }
};