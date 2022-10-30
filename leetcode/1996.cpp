class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int result = 0;
        int hi = INT_MIN;
        for (int i = properties.size() - 1; i >= 0; i--) {
            if (properties[i][1] < hi) {
                result++;
            }
            hi = max(hi, properties[i][1]);
        }
        return result;
    }
};