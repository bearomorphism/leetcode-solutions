class Solution {
private:
    vector<int> digitCount(int n) {
        vector<int> ret(10, 0);
        while (n > 0) {
            ret[n % 10]++;
            n /= 10;
        }
        return ret;
    }
public:
    bool reorderedPowerOf2(int n) {
        int s = 0;
        auto v = digitCount(n);
        int sum = accumulate(v.begin(), v.end(), 0);
        while (true) {
            auto u = digitCount(1 << s);
            if (accumulate(u.begin(), u.end(), 0) > sum) return false;
            if (u == v) return true;
            s++;
        }
    }
};