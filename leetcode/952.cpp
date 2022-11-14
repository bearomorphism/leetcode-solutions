class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        par.resize(100005);
        for (int i = 0; i < 100005; i++) {
            par[i] = i;
        }

        for (int i: nums) {
            int tmp = i;
            for (int j = 2; j*j<=tmp; j++) {
                while (tmp % j == 0) {
                    tmp /= j;
                    Union(i, j);
                }
            }
            if (tmp != 1)
                Union(i, tmp);
        }

        unordered_map<int, int> cnt;
        int result = 0;
        for (int i: nums) {
            result = max(result, ++cnt[Find(i)]);
        }
        return result;
    }
private:
    vector<int> par;
    int Find(int x) {
        if (x == par[x]) return x;
        return par[x] = Find(par[x]);
    }
    void Union(int x, int y) {
        par[Find(x)] = Find(y);
    }
};