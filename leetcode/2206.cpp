class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> v(501, false);
        for (int i: nums) {
            v[i] = !v[i];
        }
        for (int i = 1; i <= 500; i++) {
            if (v[i]) return false;
        }
        return true;
    }
};