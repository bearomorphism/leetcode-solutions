class Solution {
private:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        int row2 = n / 2, col2 = n / 2 + (n % 2);
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < col2; j++) {
                int tmp = mat[i][j];
                mat[i][j] = mat[j][n - i - 1];
                mat[j][n - i - 1] = mat[n - i - 1][n - j - 1];
                mat[n - i - 1][n - j - 1] = mat[n - j - 1][i];
                mat[n - j - 1][i] = tmp;
            }
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};