class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end()), hi = 50000 * 500;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (helper(weights, days, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
private:
    bool helper(vector<int> &w, int d, int c) {
        int cur = c;
        for (int x: w) {
            if (cur < x) {
                cur = c;
                d--;
                if (d == 0) return false;
            }
            cur -= x;
        }
        return true;
    }
};