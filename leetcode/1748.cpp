class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(101);
        for (int n : nums) {
            cnt[n]++;
        }
        int sum = 0;
        for (int i = 1; i < 101; i++) {
            if (cnt[i] == 1) {
                sum += i;
            }
        }
        return sum;
    }
};