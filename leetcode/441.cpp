class Solution {
public:
    int arrangeCoins(int n) {
        return floor((-1 + sqrt(1 + 8 * (long long)n)) / 2);
    }
};