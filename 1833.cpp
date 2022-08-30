class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ret = 0, i = 0;
        while (i < costs.size() && coins >= costs[i]) {
            coins -= costs[i];
            ret++;
            i++;
        }
        return ret;
    }
};