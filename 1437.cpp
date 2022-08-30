class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        while (i < n && !nums[i]) i++;
        while (i < n) {
            int j = i + 1;
            while (j < n && !nums[j]) j++;
            if (j == n) return true;
            if (j - i <= k) return false;
            i = j;
        }
        return true;
    }
};