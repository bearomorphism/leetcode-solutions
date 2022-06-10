class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        vector<int> prev_pos(1000006, INT_MAX);
        int res = INT_MAX;
        for (int i = 0; i < cards.size(); i++)
        {
            if (prev_pos[cards[i]] != INT_MAX)
            {
                res = min(res, i - prev_pos[cards[i]]);
            }
            prev_pos[cards[i]] = i;
        }
        if (res == INT_MAX)
        {
            return -1;
        }
        return res + 1;
    }
};