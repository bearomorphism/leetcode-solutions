class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> cnt;
        for (int i: hand) {
            cnt[i]++;
        }
        while (!cnt.empty()) {
            auto it = cnt.begin();
            auto [x, y] = *it;
            // cout << x << ' ' << y << '\n';
            if (y < 0) return false;
            if (y == 0) cnt.erase(it);
            else
                for (int i = 0; i < groupSize; i++) {
                    cnt[x + i] -= y;
                    // cout << cnt[x + i] << '\n';
                }
        }
        return true;
    }
};