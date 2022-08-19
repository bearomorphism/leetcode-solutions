class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        vector<bool> visited(s.length(), false);
        queue<int> q;
        q.push(0);
        if (s.back() != '0')
            return false;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == s.length() - 1)
                return true;
            for (int i = min(cur + maxJump, (int)s.length() - 1); i >= cur + minJump && !visited[i]; i--)
            {
                visited[i] = true;
                if (s[i] == '0')
                {
                    q.push(i);
                }
            }
        }
        return false;
    }
};