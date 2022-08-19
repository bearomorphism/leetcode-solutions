class Solution
{
private:
    void dfs(vector<vector<char>> &tmp, vector<vector<char>> &o, int i, int j)
    {
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        if (i < 0 || i >= tmp.size() || j < 0 || j >= tmp[0].size() || tmp[i][j] == 'X')
            return;
        tmp[i][j] = 'X';
        o[i][j] = 'O';
        for (int d = 0; d < 4; d++)
        {
            dfs(tmp, o, i + dx[d], j + dy[d]);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        vector<vector<char>> tmp(board);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board[i][j] = 'X';
            }
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i][0] == 'O')
                dfs(tmp, board, i, 0);
            if (tmp[i][tmp[i].size() - 1] == 'O')
                dfs(tmp, board, i, tmp[i].size() - 1);
        }
        for (int j = 0; j < tmp[0].size(); j++)
        {
            if (tmp[0][j] == 'O')
                dfs(tmp, board, 0, j);
            if (tmp[tmp.size() - 1][j] == 'O')
                dfs(tmp, board, tmp.size() - 1, j);
        }
    }
};