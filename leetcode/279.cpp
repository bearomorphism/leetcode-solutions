class Solution {
public:
    int numSquares(int n) {
        if (helper(n))
            return 1;
        for (int i = 1; i * i <= n / 2; i++) {
            if (helper(n - i * i)) return 2;
        }
        if (legendre(n)) return 3;
        return 4;
    }
private:
    bool helper(int n) {
        int i = sqrt(n);
        return i * i == n;
    }
    bool legendre(int n) {
        while (n % 4 == 0) n /= 4;
        return n % 8 != 7;
    }
};