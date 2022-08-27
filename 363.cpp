class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int ret = INT_MIN;
        for (int i = 0; i < col; i++) {
            vector<int> sums(row, 0);
            for (int j = i; j < col; j++) {
                for (int r = 0; r < row; r++) {
                    sums[r] += matrix[r][j];
                }

                set<int> s;
                s.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum: sums) {
                    curSum += sum;
                    auto it = s.lower_bound(curSum - k);
                    if (it != s.end()) curMax = max(curMax, curSum - *it);
                    s.insert(curSum);
                }
                ret = max(ret, curMax);
            }
        }
        return ret;
    }
};