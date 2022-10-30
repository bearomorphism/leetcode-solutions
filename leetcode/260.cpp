class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long d = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        d &= -d;
        vector<int> ret(2, 0);
        for (int i: nums) {
            ret[!(i & d)] ^= i;
        }
        return ret;
    }
};