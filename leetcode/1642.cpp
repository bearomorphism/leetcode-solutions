class Solution {
private:
    bool check(vector<int>& heights, int bricks, int ladders, int idx) {
        vector<int> v;
        for (int i = 0; i < idx; i++) {
            int tmp = heights[i + 1] - heights[i];
            if (tmp > 0) v.push_back(tmp);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int i = ladders; i < v.size(); i++) {
            bricks -= v[i];
            if (bricks < 0) return false;
        }
        return true;
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(heights, bricks, ladders, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};