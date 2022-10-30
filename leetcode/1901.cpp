class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int lo = 0, hi = col - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int a = -1, b = -1;
            for (int i = 0; i < row; i++) {
                a = max(a, mat[i][mid]);
                b = max(b, mat[i][mid + 1]);
            }
            if (a < b) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        int r = -1, m = -1;
        for (int i = 0; i < row; i++) {
            if (m < mat[i][hi]) {
                m = mat[i][hi];
                r = i;
            }
        }
        return {r, hi};
    }
};