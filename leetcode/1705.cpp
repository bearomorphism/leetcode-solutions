class Solution {
    using P = pair<int, int>;
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<P, vector<P>, greater<P>> pq; // rotten day, idx
        int n = apples.size(), result = 0;
        for (int i = 0; i < n || !pq.empty(); i++) {
            if (i < n) pq.push({i + days[i], i});
            while (!pq.empty()) {
                auto [rot, idx] = pq.top();
                if (rot <= i || apples[idx] == 0) {
                    pq.pop();
                } else {
                    result++;
                    apples[idx]--;
                    break;
                }
            }
        }
        return result;
    }
};