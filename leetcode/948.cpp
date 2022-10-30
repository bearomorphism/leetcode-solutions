class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int result = 0, l = 0, r = n - 1, cur = 0;
        while (l <= r && power >= tokens[l]) {
            power -= tokens[l];
            l++;
            cur++;
            result = max(result, cur);
            if (l < r && tokens[l] > power && tokens[l] <= power + tokens[r]) {
                power += tokens[r];
                r--;
                cur--;
            }
        }
        return result;
    }
};