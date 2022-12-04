class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = 0, cur = 0, last = 0;
        for (int i: nums) {
            if (i > last) {
                cur += i;
                result = max(result, cur);
            } else {
                cur = i;
            }
            last = i;
        }
        return result;
    }
};