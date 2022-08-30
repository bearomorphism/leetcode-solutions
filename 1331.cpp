class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ret(arr.begin(), arr.end());
        if (arr.size() == 0) return ret;
        sort(arr.begin(), arr.end());
        int r = 1;
        unordered_map<int, int> um;
        um[arr[0]] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1]) um[arr[i]] = ++r;
        }
        for (int i = 0; i < ret.size(); i++) {
            ret[i] = um[ret[i]];
        }
        return ret;
    }
};