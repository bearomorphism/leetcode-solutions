class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
         map<int, int> cnt;
        for (int i: nums) {
            cnt[i]++;
        }
        while (!cnt.empty()) {
            auto it = cnt.begin();
            auto [x, y] = *it;
            // cout << x << ' ' << y << '\n';
            if (y < 0) return false;
            if (y == 0) cnt.erase(it);
            else
                for (int i = 0; i < k; i++) {
                    cnt[x + i] -= y;
                    // cout << cnt[x + i] << '\n';
                }
        }
        return true;
    }
};