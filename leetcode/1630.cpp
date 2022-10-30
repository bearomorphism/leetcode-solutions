class Solution {
private:
    bool check(vector<int> &v) {
        int diff = v[1] - v[0];
        for (int i = 2; i < v.size(); i++) {
            if (v[i] - v[i - 1] != diff) return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ret;
        for (int i = 0; i < n; i++) {
            int a = l[i], b = r[i];
            vector<int> v;
            for (int j = a; j <= b; j++) {
                v.push_back(nums[j]);
            }
            sort(v.begin(), v.end());
            ret.push_back(check(v));
        }
        return ret;
    }
};