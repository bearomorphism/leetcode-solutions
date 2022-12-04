class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        int m = 1e9 + 7;
        long long result = 0;
        for (int i: nums) {
            long long x = i - rev(i);
            result = (result + cnt[x]++) % m;
        }
        return result;
    }
private:
    long long rev(int n) {
        long long ret = 0;
        while (n) {
            ret = ret * 10 + n % 10;
            n /= 10;
        }
        return ret;
    }
};