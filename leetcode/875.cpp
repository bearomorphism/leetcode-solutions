class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi = 1000000000, lo = 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (helper(piles, h, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
private:
    bool helper(vector<int> &piles, int h, int k) {
        for (int p: piles) {
            h -= (p / k + (p % k ? 1 : 0));
            if (h < 0) return false;
        }
        return true;
    }
};