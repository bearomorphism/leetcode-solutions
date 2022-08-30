class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int a = 0, mh = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for (int i: horizontalCuts) {
            mh = max(mh, i - a);
            a = i;
        }
        mh = max(mh, h - a);
        int b = 0, mw = 0;
        for (int i: verticalCuts) {
            mw = max(mw, i - b);
            b = i;
        }
        mw = max(mw, w - b);
        return ((long long)mh * mw ) % 1000000007;
    }
};