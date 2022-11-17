class Solution {
public:
    int integerReplacement(int n) {
        int result = 0;
        if (n == INT_MAX) {
            n = 1073741824;
            result = 2;
        }
        while (n > 1) {
            if (!(n & 1)) {
                n >>= 1;
            } else if (n == 3 || n % 4 == 1) n--;
            else n++;
            result++;
        }
        return result;
    }
};