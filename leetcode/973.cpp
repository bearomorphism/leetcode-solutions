class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];});
        vector<vector<int>> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(points[i]);
        }
        return ret;
    }
};