class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> um;
        long long time = 0;
        for (int t: tasks) {
            // cout << time << ' ' << um[t] << '\n';
            time = max(time, um[t]) + 1;
            um[t] = time + space;
        }
        return time;
    }
};