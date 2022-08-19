class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> d(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            vector<int> v(triangle[i].size());
            for (int j = 0; j < triangle[i].size(); j++)
            {
                v[j] = triangle[i][j] + min(d[j], d[j + 1]);
            }
            d = v;
        }
        return d[0];
    }
};