class Solution {
public:
    bool canCross(vector<int>& stones) {
        int goal = stones.back();
        unordered_map<int, unordered_set<int>> um;
        for (int i: stones) {
            um[i] = unordered_set<int>();
        }
        um[0].insert(0);
        for (int s: stones) {
            for (auto q: um[s]) {
                for (int d = -1; d <= 1; d++) {
                    int step = q + d;
                    if (step > 0) {
                        if (s + step == goal) return true;
                        auto it = um.find(s + step);
                        if (it != um.end()) {
                            it->second.insert(step);
                        }
                    }
                }
            }
        }
        return false;
    }
};