class Solution
{
public:
    unordered_map<int, int> um;
    int m, cur;
    Solution(int n, vector<int> &blacklist)
    {
        m = n;
        int idx = 0;
        for (auto &i : blacklist)
        {
            auto p = um.find(idx);
            um[i] = p == um.end() ? idx : p->second;
            idx = (idx + 1) % m;
        }
        cur = 0;
    }

    int pick()
    {
        cur = (cur + 1) % m;
        auto p = um.find(cur);
        return p == um.end() ? cur : p->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */