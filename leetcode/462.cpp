class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums[nums.size() / 2];
        int ret = 0;
        for (int &i: nums) {
            ret += abs(i - m);
        }
        return ret;
    }
};