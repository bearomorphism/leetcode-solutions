class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = INT_MAX, ans = INT_MIN;
        for (int i: nums) {
            int d = abs(i);
            if (d < dist || d == dist && i > ans) {
                dist = d;
                ans = i;
            }
        }
        return ans;
    }
};