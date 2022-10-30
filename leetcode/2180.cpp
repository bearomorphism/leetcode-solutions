class Solution {
private:
    bool check(int num) {
        bool ret = true;
        while (num) {
            if (num & 1) ret = !ret;
            num /= 10;
        }
        return ret;
    }
public:
    int countEven(int num) {
        int ret = 0;
        for (int i = 1; i <= num; i++) {
            if (check(i)) ret++;
        }
        return ret;
    }
};