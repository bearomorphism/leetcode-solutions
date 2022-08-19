class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, j = 0, cur = 0, d = 0;
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        const int nn = n * n;
        while (cur != nn)
        {
            res[i][j] = ++cur;
            int a = i + dx[d], b = j + dy[d];
            if (!(0 <= a && a < n && 0 <= b && b < n && res[a][b] == 0))
            {
                d = (d + 1) % 4;
                a = i + dx[d], b = j + dy[d];
            }
            // cout << cur << ' ' << a << ' ' << b << '\n';
            i = a;
            j = b;
        }
        return res;
    }
};