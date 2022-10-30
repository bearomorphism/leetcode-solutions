class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());
        double target = 0;
        for (int i: nums) target += i;
        target /= 2;
        int ret = 0;
        while (!pq.empty()) {
            double d = pq.top() / 2;
            pq.pop();
            pq.push(d);
            target -= d;
            ret++;
            if (target <= 0) return ret;
        }
        return ret;
    }
};