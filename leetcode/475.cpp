class Solution {
private:
    bool check(vector<int>& houses, vector<int>& heaters, int range) {
        int k = 0;
        for (int h: houses) {
            while (k < heaters.size() && h > heaters[k] + range) k++;
            if (k == heaters.size() || h < heaters[k] - range) return false;
        }
        return true;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int lo = 0, hi = 10000000000;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(houses, heaters, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
};