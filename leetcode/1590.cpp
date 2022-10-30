class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> last;
        int sum = 0;
        for (int i: nums) sum = (sum + i) % p;
        if (sum == 0) return 0;
        int cur = 0;
        last[0] = -1;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            cur = (cur + nums[i]) % p;
            int comp = (p - sum + cur) % p;
            if (last.count(comp)) ans = min(ans, i - last[comp]);
            last[cur] = i;
        }
        if (ans == nums.size()) return -1;
        return ans;
    }
};