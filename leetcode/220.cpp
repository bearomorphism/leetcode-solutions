class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        diff_ = t;
        s_ = {};
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > k) {
                s_.erase(nums[i - k - 1]);
            }
            if (isAlmost(nums[i])) return true;
            s_.insert(nums[i]);
        }
        return false;
    }
private:
    set<int> s_;
    int diff_;
    bool isAlmost(int v) {
        return s_.upper_bound(v + diff_) != s_.lower_bound(v - diff_);
    }
};