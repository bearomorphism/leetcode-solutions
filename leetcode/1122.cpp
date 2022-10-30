class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001, 0);
        for (int i: arr1) {
            cnt[i]++;
        }
        vector<int> ret;
        for (int i: arr2) {
            while (cnt[i]) {
                ret.push_back(i);
                cnt[i]--;
            }
        }
        for (int i = 0; i < cnt.size(); i++) {
            while (cnt[i]) {
                ret.push_back(i);
                cnt[i]--;
            }
        }
        return ret;
    }
};