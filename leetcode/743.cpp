class Solution {
    using P = pair<int, int>;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX);
        vector<vector<P>> edges(n);
        for (auto &t: times) {
            edges[t[0] - 1].push_back({t[1] - 1, t[2]});
        }
        priority_queue<P, vector<P>, greater<P>> pq; // dist, idx
        pq.push({0, k - 1});
        while (!pq.empty()) {
            auto [d, i] = pq.top();
            pq.pop();
            if (dist[i] == INT_MAX) {
                dist[i] = d;
                for (auto [a, b]: edges[i]) {
                    pq.push({b + d, a});
                }
            }
        }

        int result = *max_element(dist.begin(), dist.end());
        return result == INT_MAX ? -1: result;
    }
};