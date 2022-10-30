class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        int num = helper(n);
        // cout << num << '\n';
        if (target >= num) return 0;

        long long last_digit = n % 10;
        int comp = last_digit == 0 ? 0 : 10 - last_digit;
        return comp + makeIntegerBeautiful(n / 10 + (comp == 0 ? 0 : 1), target) * 10;
    }
private:
    int helper(long long n) {
        int ret = 0;
        while (n) {
            ret += n % 10;
            n /= 10;
        }
        return ret;
    }
};