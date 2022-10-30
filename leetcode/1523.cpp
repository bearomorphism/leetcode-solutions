class Solution {
public:
    int countOdds(int low, int high) {
        int ret = (high - low) / 2 + 1;
        if (!(high & 1) && !(low & 1)) ret--;
        return ret;
    }
};