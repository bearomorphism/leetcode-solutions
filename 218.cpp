class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>> pq; // the highest building's height and right edge
        int n = buildings.size(), k = 0, h = -1;
        while (k < n || !pq.empty()) {
            int l = pq.empty() ? buildings[k][0]: pq.top().second;
            if (k >= n || buildings[k][0] > l) {
                while (!pq.empty() && pq.top().second <= l) {
                    pq.pop();
                }
            } else {
                l = buildings[k][0];
                while (k < n && buildings[k][0] == l) {
                    pq.push({buildings[k][2], buildings[k][1]});
                    k++;
                }
            }
            h = pq.empty() ? 0 : pq.top().first;
            if (result.empty() || result.back()[1] != h) {
                result.push_back({l, h});
            }
        }
        return result;
    }
};