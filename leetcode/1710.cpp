class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int result = 0;
        int n = boxTypes.size();
        for (int i = 0; i < n; i++) {
            int t = min(boxTypes[i][0], truckSize);
            result += t * boxTypes[i][1];
            truckSize -= t;
        }
        return result;
    }
};