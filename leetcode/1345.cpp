class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        vector<int> dist(arr.size(), INT_MAX);
        queue<int> q;
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < arr.size(); i++)
        {
            auto p = um.find(arr[i]);
            if (p == um.end())
            {
                um[arr[i]] = vector<int>(1, i);
            }
            else
            {
                p->second.push_back(i);
            }
        }

        auto set_dist = [&](int from, int to)
        {
            // cout << from << ' ' << to << endl;
            if (0 <= to && to < dist.size() && from != to && dist[to] == INT_MAX)
            {
                dist[to] = dist[from] + 1;
                q.push(to);
            }
        };
        q.push(0);
        dist[0] = 0;
        while (!q.empty())
        {
            int cur = q.front();

            q.pop();
            set_dist(cur, cur + 1);
            set_dist(cur, cur - 1);

            auto p = um.find(arr[cur]);
            if (p != um.end())
            {
                for (auto &to : p->second)
                {
                    set_dist(cur, to);
                }
                um.erase(p);
            }
        }
        return dist[arr.size() - 1];
    }
};