class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> us(nums.begin(), nums.end());
        while (us.count(original)) original <<= 1;
        return original;
    }
};