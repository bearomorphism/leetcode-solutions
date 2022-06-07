class Solution
{
private:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        for (int d = 0; d < 4; d++)
        {
            dfs(grid, i + dx[d], j + dy[d]);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};