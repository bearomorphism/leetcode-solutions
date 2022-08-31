class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long cur = 1, ret = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] == prices[i - 1] - 1) cur++;
            else {
                ret += cur * (cur + 1) / 2;
                cur = 1;
            }
        }
        ret += cur * (cur + 1) / 2;
        return ret;
    }
};