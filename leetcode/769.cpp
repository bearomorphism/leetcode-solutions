class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {arr[i], i};
        }
        sort(v.begin(), v.end());
        int result = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int x = v[i].second;
            cur = max(cur, x);
            if (cur <= i) result++;
        }
        return result;
    }
};