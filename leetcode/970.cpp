class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int a = 1;
        unordered_set<int> us;
        while (a < bound) {
            int b = 1;
            while (a + b <= bound) {
                us.insert(a + b);
                b *= y;
                if (y == 1) break;
            }
            a *= x;
            if (x == 1) break;
        }
        return vector<int>(us.begin(), us.end());
    }
};