class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> idx{-1};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) idx.push_back(i);
        }
        idx.push_back(nums.size());
        int result = 0;
        for (int i = 1; i + k < idx.size(); i++) {
            result += (idx[i] - idx[i - 1]) * (idx[i + k] - idx[i + k - 1]);
        }
        return result;
    }
};