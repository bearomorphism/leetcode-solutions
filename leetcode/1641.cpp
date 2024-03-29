class Solution {
public:
    int countVowelStrings(int n) {
        return nChoosek(n + 4, 4);
    }
private:
    inline unsigned nChoosek(unsigned n, unsigned k) {
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        int result = n;
        for( int i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }

};