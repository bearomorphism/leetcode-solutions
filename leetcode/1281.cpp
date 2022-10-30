class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> v;
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }
        int sum = accumulate(v.begin(), v.end(), 0);
        int prod = accumulate(v.begin(), v.end(), 1, multiplies<int>());
        return prod - sum;
    }
};