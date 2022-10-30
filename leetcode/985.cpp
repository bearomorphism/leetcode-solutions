class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;

        int sum = 0;
        for (int i: nums) {
            if (!(i & 1)) sum += i;
        }
        for (auto &q: queries) {
            int value = q[0], index = q[1];
            int before = nums[index];
            int after = (nums[index] += q[0]);
            if (!(before & 1)) sum -= before;
            if (!(after & 1)) sum += after;
            result.push_back(sum);
        }

        return result;
    }
};