class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());
        long long l = mass;
        for (auto &i : asteroids)
        {
            if (l < i)
            {
                return false;
            }
            l += i;
        }
        return true;
    }
};