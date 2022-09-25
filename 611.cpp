class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        vector<int> v;
        for (int i: nums) {
            if (i > 0) v.push_back(i);
        }
        sort(v.begin(), v.end());
        int n = v.size();
        int result = n * (n - 1) * (n - 2) / 6;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = v[i] + v[j];
                int x = v.end() - lower_bound(v.begin(), v.end(), target);
                cout << x << '\n';
                result -= x;
            }
        }
        return result;
    }
};