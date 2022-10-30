class Solution {
private:
    bool check(int n) {
        int t = n;
        while (t) {
            int x = t % 10;
            if (!x || n % x) return false;
            t /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for (int i = left; i <= right; i++) {
            if (check(i)) ret.push_back(i);
        }
        return ret;
    }
};