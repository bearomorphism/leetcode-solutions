class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        auto orientation = [&](int i, int j, int k) {
            auto &p = trees[i], &q = trees[j], &r = trees[k];
            return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
        };

        vector<int> hull;
        int n = trees.size();
        for (int i = 0; i < n; i++) {
            while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], i) > 0) {
                hull.pop_back();
            }
            hull.push_back(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], i) > 0) {
                hull.pop_back();
            }
            hull.push_back(i);
        }

        unordered_set<int> us(hull.begin(), hull.end());

        vector<vector<int>> result;
        for (int i: us) {
            result.push_back(trees[i]);
        }

        return result;
    }
};