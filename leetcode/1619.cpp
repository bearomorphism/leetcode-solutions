class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int t = n / 20;
        return (double)accumulate(arr.begin() + t, arr.end() - t, 0) / (n - t * 2);
    }
};