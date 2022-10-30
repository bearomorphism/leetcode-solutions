class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }
        for (int i = k; i < nums.size(); i++) {
            ret.push_back(nums[q.front()]);
            while (!q.empty() && q.front() <= i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }
        ret.push_back(nums[q.front()]);
        return ret;
    }
};