class Solution {
public:
    bool isThree(int n) {
        if (n == 1) return false;
        int i = 2;
        while (i * i < n) {
            if (n % i == 0) return false;
            i++;
        }
        return i * i == n;
    }
};