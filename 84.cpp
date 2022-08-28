class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int j = 0, ret = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int h = i == heights.size() ? 0 : heights[i];
            if (s.empty() || h >= heights[s.top()]) {
                s.push(i);
            } else {
                int tp = s.top();
                s.pop();
                ret = max(ret, heights[tp] * (s.empty() ? i : i - 1 - s.top()));
                i--;
            }
        }
        return ret;
    }
};