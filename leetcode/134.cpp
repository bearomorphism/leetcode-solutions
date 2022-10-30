class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            v[i] = gas[i] - cost[i];
        }
        int l = 0;
        while (l < n && v[l] < 0) l++;
        if (l == n) return -1;
        int r = l;
        int g = v[l];
        while (l < n) {
            r++;
            g += v[r % n];
            while (l < n && g < 0) {
                g -= v[l];
                l++;
            }
            if (r == l + n) return l;
        }
        return -1;
    }
};