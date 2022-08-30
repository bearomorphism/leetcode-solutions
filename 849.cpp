class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (seats[i]) v.push_back(i);
        }
        int ret = max(v[0], n - v.back() - 1);
        for (int i = 1; i < v.size(); i++) {
            ret = max(ret, (v[i] - v[i - 1]) / 2);
        }
        return ret;
    }
};