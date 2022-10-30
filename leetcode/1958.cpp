class Solution {
private:
    char flip(char color) {
        if (color == 'W') return 'B';
        if (color == 'B') return 'W';
        return '.';
    }
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        const int dx[] = {1, 1, 1, 0, -1, -1, -1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < 8; i++) {
            int u = rMove + dx[i], v = cMove + dy[i];
            if (0 <= min(u, v) && max(u, v) < 8 && board[u][v] == flip(color)) {
                int j = 2;
                while (true) {
                    int a = rMove + j * dx[i], b = cMove + j * dy[i];
                    if (0 <= min(a, b) && max(a, b) < 8 && board[a][b] != '.') {
                        if (board[a][b] == color) return true;
                        j++;
                    } else break;
                }
            }
        }
        return false;
    }
};