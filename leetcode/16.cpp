class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans{0}, dist{INT_MAX};
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int tmp = target - nums[i] - nums[j];
                while (j < k && tmp <= nums[k]) {
                    int d = abs(tmp - nums[k]);
                    if (d < dist) {
                        ans = nums[i] + nums[j] + nums[k];
                        dist = d;
                    }
                    k--;
                }
                if (j < k) {
                    int d = abs(tmp - nums[k]);
                    if (d < dist) {
                        ans = nums[i] + nums[j] + nums[k];
                        dist = d;
                    }
                }

                j++;
            }
        }

        return ans;
    }
};