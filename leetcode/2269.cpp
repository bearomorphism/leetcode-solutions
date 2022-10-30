class Solution {
public:
    int divisorSubstrings(int num, int k) {
        long long t = num;
        long long div = 1;
        while (k--) {
            div *= 10;
        }
        int ret = 0;
        while (t * 10 >= div) {
            long long d = t % div;
            if (d && num % d == 0) ret++;
            t /= 10;
        }
        return ret;
    }
};