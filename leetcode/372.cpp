class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int m = 1337;
        a %= m;
        int ret = 1;
        vector<int> v(10);
        v[0] = 1;
        for (int i = 1; i < 10; i++) {
            v[i] = a * v[i - 1] % m;
        }
        for (int n: b) {
            int tmp = ret;
            for (int i = 0; i < 9; i++) {
                ret = ret * tmp % m;
                cout << ret << '\n';
            }
            ret = ret * v[n] % m;
        }
        return ret;
    }
};