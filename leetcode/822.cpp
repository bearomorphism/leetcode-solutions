class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        vector<bool> rec(2001);
        for (int i = 0; i < n; i++) {
            rec[fronts[i]] = rec[backs[i]] = true;
        }
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) rec[fronts[i]] = false;
        }
        for (int i = 1; i < 2001; i++) {
            if (rec[i]) return i;
        }
        return 0;
    }
};