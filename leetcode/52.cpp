class Solution
{
private:
    vector<string> tmp;
    vector<vector<string>> ans;
    void dfs(int depth, int n)
    {
        if (depth == n)
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isValid(depth, i))
            {
                string s(n, '.');
                s[i] = 'Q';
                tmp.push_back(s);
                dfs(depth + 1, n);
                tmp.pop_back();
            }
        }
    }

    bool isValid(int x, int y)
    {
        for (int i = 0; i < tmp.size(); i++)
        {
            int u = y - (x - i), v = y + (x - i);
            if (tmp[i][y] == 'Q' || 0 <= u && u < tmp[i].size() && tmp[i][u] == 'Q' || 0 <= v && v < tmp[i].size() && tmp[i][v] == 'Q')
                return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        ans.clear();
        dfs(0, n);
        return ans;
    }

public:
    int totalNQueens(int n)
    {
        return solveNQueens(n).size();
    }
};