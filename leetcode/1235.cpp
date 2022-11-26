class Solution {
    using T = tuple<int, int, int>;
    using P = pair<int, int>;
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // find the maximum profit before start time
        int n = startTime.size();
        vector<T> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(v.begin(), v.end());
        priority_queue<P, vector<P>, greater<P>> pq; // end, total profit
        int cur = 0, result = 0;
        for (const auto &[s, e, p]: v) {
            while (!pq.empty() && pq.top().first <= s) {
                cur = max(cur, pq.top().second);
                pq.pop();
            }
            int cur_profit = cur + p;
            result = max(result, cur_profit);
            pq.push({e, cur_profit});
        }
        return result;
    }
};
