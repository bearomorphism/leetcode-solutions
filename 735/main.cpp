class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> res;
        for (auto &astroid : asteroids)
        {
            if (astroid > 0)
                res.push_back(astroid);
            else
            {
                while (!res.empty() && res.back() > 0 && res.back() < -astroid)
                {
                    res.pop_back();
                }
                if (!res.empty() && res.back() == -astroid)
                    res.pop_back();
                else if (res.empty() || res.back() < 0)
                    res.push_back(astroid);
            }
        }
        return res;
    }
};