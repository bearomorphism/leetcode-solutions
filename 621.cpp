class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> um;
        int cnt = 0;
        for (char &c: tasks) {
            um[c]++;
            cnt = max(cnt, um[c]);
        }
        int ret = (cnt - 1) * (n + 1);
        for (auto &p: um) {
            if (p.second == cnt) ret++;
        }
        return max(ret, (int)tasks.size());
    }
};