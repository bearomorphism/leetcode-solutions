class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int cnt = 1;
        int s = points.back()[0];
        int n = points.size();
        for (int i = n - 2; i >= 0; i--) {
            if (points[i][1] < s) {
                s = points[i][0];
                cnt++;
            }
        }
        return cnt;
    }
};