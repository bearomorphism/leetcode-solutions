class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> um;
        int ret = 1;
        for (int i: arr) {
            um[i] = um[i - difference] + 1;
            ret = max(ret, um[i]);
        }
        return ret;
    }
};