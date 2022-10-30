class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result(k);
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (idx == n) {
            idx = n - 1;
        }
        int l = idx, r = idx;
        // cout << idx << '\n';
        while (k && r < n && l > 0) {
            // cout << l << ' ' << r << '\n';
            int dl = x - arr[l - 1], dr = arr[r] - x;
            if (dl <= dr) l--;
            else r++;
            k--;
        }
        while (k && l > 0) {
            l--;
            k--;
        }
        while (k && r < n) {
            r++;
            k--;
        }

        for (int i = l; i < r; i++) {
            result[i - l] = arr[i];
        }
        return result;
    }
};