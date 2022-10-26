class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cur = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            cur = (cur + nums[i]) % k;
            if (mp.count(cur)) {
                if(i - mp[cur] >= 2) {
                    return true;
                }
            } else {
                mp[cur] = i;
            }
        }
        return false;
    }
};

