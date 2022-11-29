class Solution {
    using P = pair<int, int>;
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<P> v;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                v.push_back({arr[i], arr[j]});
            }
        }
        sort(v.begin(), v.end(), [](P x, P y) {
            return x.first * y.second < x.second * y.first;
        });
        return {v[k - 1].first, v[k - 1].second};
    }
};