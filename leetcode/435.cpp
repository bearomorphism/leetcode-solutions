class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int cnt = 1, s = intervals.back()[0];
        for (int i = n - 2; i >= 0; i--) {
            if (intervals[i][1] <= s) {
                s = intervals[i][0];
                cnt++;
            }
        }
        return n - cnt;
    }
};