class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> u;
        pq.push(1);
        n--;
        while (n) {
            long long cur = pq.top();
            pq.pop();
            vector<long long> v({cur * 2, cur * 3, cur * 5});
            for (auto i: v) {
                if (u.find(i) == u.end()) {
                    pq.push(i);
                    u.insert(i);
                }
            }
            n--;
        }
        return pq.top();
    }
};