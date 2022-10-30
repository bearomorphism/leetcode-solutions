class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 1);
        for (int i: nums) {
            v[i]++;
        }

        int a{0}, b{0};
        for (int j = 1; j <= n; j++) {
            if (v[j] == 2) a = j;
            else if (v[j] == 0) b = j;
        }
        return {a, b};
    }
};