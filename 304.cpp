class NumMatrix
{
public:
    vector<vector<int>> m;
    NumMatrix(vector<vector<int>> &matrix)
    {
        m = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); i++)
        {
            for (int j = 1; j <= matrix[0].size(); j++)
            {
                m[i][j] = m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return m[row2 + 1][col2 + 1] - m[row2 + 1][col1] - m[row1][col2 + 1] + m[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */