class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            x = __gcd(x, nums[i]);
        }
        return x == 1;
    }
};