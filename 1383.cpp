class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end()); // sort by efficiency
        reverse(v.begin(), v.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long speedSum = 0, result = 0;
        for (int i = 0; i < n; i++) {
            pq.push(v[i].second);
            speedSum += v[i].second;
            if (i >= k) {
                speedSum -= pq.top();
                pq.pop();
            }
            result = max(result, speedSum * v[i].first);
        }
        return result % 1000000007;
    }
};