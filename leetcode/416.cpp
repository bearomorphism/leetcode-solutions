class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int summ = accumulate(nums.begin(), nums.end(), 0);
        if (summ & 1) return false;

        int target = summ / 2;
        vector<bool> vis(target);
        vis[0] = true;
        sort(nums.begin(), nums.end());
        int cur = 0;
        for (int i: nums) {
            for (int j = cur; j >= 0; j--) {
                if (vis[j]) {
                    int nex = j + i;
                    if (nex == target) return true;
                    else if (nex < target) {
                        vis[nex] = true;
                        cur = max(cur, nex);
                    }
                }
            }
        }
        return false;
    }
};