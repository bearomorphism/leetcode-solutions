class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for (auto &p: points) {
            unordered_map<int, int> um;
            for (auto &q: points) {
                int a = p[0] - q[0], b = p[1] - q[1];
                int tmp = a * a + b * b;
                auto it = um.find(tmp);
                if (it == um.end()) um[tmp] = 0;
                ret += um[tmp];
                um[tmp]++;
            }
        }
        return ret * 2;
    }
};