class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int result{0}, n = nums.size();
        deque<int> dq;
        for (int i = n - 1; i >= 0; i--) {
            result = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);
            while (!dq.empty() && result > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if (dq.front() >= i + k)
                dq.pop_front();
            nums[i] = result;
        }
        return result;
    }
};