class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int m = 10001;
        vector<vector<int>> r(m), c(m);
        int n = stones.size();
        for (int i = 0; i < stones.size(); i++) {
            r[stones[i][0]].push_back(i);
            c[stones[i][1]].push_back(i);
        }

        Init(n);
        for (int i = 0; i < m; i++) {
            if (!r[i].empty()) {
                for (int j = 1; j < r[i].size(); j++) {
                    Union(r[i][0], r[i][j]);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (!c[i].empty()) {
                for (int j = 1; j < c[i].size(); j++) {
                    Union(c[i][0], c[i][j]);
                }
            }
        }

        int result = n;
        for (int i = 0; i < n; i++) {
            if (i == Find(i)) {
                result--;
            }
        }
        return result;
    }
private:
    vector<int> parent_;
    void Init(int n) {
        parent_ = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent_[i] = i;
        }
    }
    int Find(int x) {
        if (parent_[x] == x) return x;
        return parent_[x] = Find(parent_[x]);
    }
    void Union(int x, int y) {
        parent_[Find(x)] = Find(y);
    }
};