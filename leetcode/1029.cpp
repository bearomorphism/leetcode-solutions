class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0] - a[1] < b[0] - b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compare);
        int result = 0;
        int m = costs.size() / 2;
        for (int i = 0; i < m; i++) {
            result += costs[i][0];
        }
        for (int i = m; i < costs.size(); i++) {
            result += costs[i][1];
        }
        return result;
    }
};