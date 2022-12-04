class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool neg = false;
        for (int i: nums) {
            if (i == 0) return 0;
            if (i < 0) neg = !neg;
        }
        return neg ? -1 : 1;
    }
};