class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i = 0, n = arr.size();
        unordered_map<int, int> cnt;
        while (i < n && arr[i] < 0) {
            if (cnt[arr[i] * 2] > 0) {
                cnt[arr[i] * 2]--;
            } else {
                cnt[arr[i]]++;
            }
            i++;
        }
        for (auto it: cnt) {
            if (it.second > 0) return false;
        }
        int zero = 0;
        while (i < n && arr[i] == 0) {
            zero++;
            i++;
        }
        if (zero & 1) return false;
        cnt.clear();
        while (i < n) {
            if (!(arr[i] & 1) && cnt[arr[i] / 2] > 0) {
                cnt[arr[i] / 2]--;
            } else {
                cnt[arr[i]]++;
            }
            i++;
        }
        for (auto it: cnt) {
            if (it.second > 0) return false;
        }
        return true;
    }
};