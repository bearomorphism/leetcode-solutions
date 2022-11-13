class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        auto helper = [&](int i, int j) -> pair<int, int> {
            int a = points[i][1] - points[j][1];
            int b = points[i][0] - points[j][0];
            int g = __gcd(a, b);
            a /= g;
            b /= g;
            if (a < 0 && b > 0) {
                a = -a;
                b = -b;
            }
            return {a, b};
        };
        int n = points.size();
        int result = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto slope = helper(i, j);
                int cur = 2;
                for (int k = j + 1; k < n; k++) {
                    if (helper(i, k) == slope) cur++;
                }
                result = max(result, cur);
            }
        }
        return result;
    }
};