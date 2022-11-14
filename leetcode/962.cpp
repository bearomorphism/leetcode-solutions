class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int result = 0, n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                result = max(result, i - st.top());
                st.pop();
            }
        }
        return result;
    }
};