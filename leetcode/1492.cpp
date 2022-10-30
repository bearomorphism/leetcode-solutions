class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> v1, v2;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                v1.push_back(i);
                if (i * i != n) {
                    v2.push_back(n / i);
                }
            }
        }
        k--;
        if (k < v1.size()) return v1[k];
        k -= v1.size();
        if (k < v2.size()) return v2[v2.size() - 1 - k];
        return -1;
    }
};