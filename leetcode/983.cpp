class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1);
        int p7 = 0, p30 = 0;
        for (int i = 0; i < n; i++) {
            while (days[p7] + 7 <= days[i]) p7++;
            while (days[p30] + 30 <= days[i]) p30++;
            dp[i + 1] = min({
                dp[i] + costs[0],
                dp[p7] + costs[1],
                dp[p30] + costs[2]
            });
        }
        return dp.back();
    }
};