class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        int ret = 0;
        while (num >= 0 && ret <= 10) {
            if (num % 10 == 0 && ret > 0) return ret;
            num -= k;
            ret++;
        }
        return -1;
    }
};