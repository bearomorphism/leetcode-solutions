class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> toFlip;
        const int dx[] = {1, 1, 1, 0, -1, -1, -1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int cnt = 0;
                for (int d = 0; d < 8; d++) {
                    int x = i + dx[d], y = j + dy[d];
                    if (x >= 0 && x < board.size() && y >= 0 && y < board[i].size() && board[x][y]) cnt++;
                }
                if (board[i][j] && (cnt > 3 || cnt < 2) || !board[i][j] && cnt == 3) toFlip.push_back({i, j});
            }
        }
        for (auto p: toFlip) {
            board[p.first][p.second] = !board[p.first][p.second];
        }
    }
};