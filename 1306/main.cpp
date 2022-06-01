class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        vector<bool> visited(arr.size(), false);
        queue<int> q;
        if (arr[start] == 0)
            return true;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            const int d[] = {-1, 1};
            for (int i = 0; i < 2; i++)
            {
                int to = cur + arr[cur] * d[i];
                if (0 <= to && to < arr.size() && !visited[to])
                {
                    if (arr[to] == 0)
                        return true;
                    visited[to] = true;
                    q.push(to);
                }
            }
        }
        return false;
    }
};