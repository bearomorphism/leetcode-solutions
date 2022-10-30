class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        for (int i = 0; i < k; i++) {
            int t = pq.top();
            pq.pop();
            pq.push(t + 1);
        }
        long long result = 1;
        while (!pq.empty()) {
            result = (result * pq.top()) % (int)(1e9 + 7);
            pq.pop();
        }
        return result;
    }
};