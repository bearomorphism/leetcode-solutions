class Solution {
public:
    int minCost(const string &colors, vector<int>& neededTime) {
        int n = colors.length();
        int i{0};
        int result{0};
        while (i < n) {
            int sum = neededTime[i], m = neededTime[i];
            i++;
            if (i < n && colors[i] == colors[i - 1]) {
                while (i < n && colors[i] == colors[i - 1]) {
                    m = max(m, neededTime[i]);
                    sum += neededTime[i];
                    i++;
                }
                result += sum - m;
            }
        }
        return result;
    }
};