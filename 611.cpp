class Solution {
public:
    int triangleNumber(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            int k = i + 2;
            for (int j = i + 1; j < n; j++) {
                k = max(k, j + 1);
                int tmp = v[i] + v[j];
                while (k < n && tmp > v[k]) k++;
                result += k - j - 1;
            }
        }
        return result;
    }
};