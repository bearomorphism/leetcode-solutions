class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int l = max(ax1, bx1);
        int r = min(ax2, bx2);
        int b = max(ay1, by1);
        int t = min(ay2, by2);

        int x = r - l, y = t - b;
        int overlap = x > 0 && y > 0 ? x * y : 0;

        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - overlap;
    }
};