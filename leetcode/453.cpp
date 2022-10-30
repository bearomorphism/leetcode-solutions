class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = *min_element(nums.begin(), nums.end());
        int ret = 0;
        for (int &i: nums) {
            ret += i - m;
        }
        return ret;
    }
};