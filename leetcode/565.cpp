class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n);
        int ret = 1;
        for (int i = 0; i < n; i++) {
            int cnt = 0, cur = i;
            while (!vis[cur]) {
                vis[cur] = true;
                cnt++;
                cur = nums[cur];
            }
            ret = max(ret, cnt);
        }
        return ret;
    }
};