class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> cnt(10);
        int sum = 0;
        for (int i: digits) {
            cnt[i]++;
            sum += i;
        }
        int remainder = sum % 3;
        fix(cnt, remainder);
        string ret{};
        for (int i = 9; i >= 0; i--) {
            if (i == 0 && ret.length() == 0) return cnt[0] == 0 ?  : 0;
            for (int _ = 0; _ < cnt[i]; _++) {
                ret.push_back(i + '0');
            }
        }
        return ret;
    }
private:
    void fix(vector<int> &cnt, int remainder) {
        if (remainder == 2) {
            for (int i: {2, 5, 8}) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    return;
                }
            }
            int x = 2;
            for (int i: {1, 4, 7}) {
                while (x && cnt[i] > 0) {
                    x--;
                    cnt[i]--;
                }
            }
            return;
        }
        if (remainder == 1) {
            for (int i: {1, 4, 7}) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    return;
                }
            }
            int x = 2;
            for (int i: {2, 5, 8}) {
                while (x && cnt[i] > 0) {
                    x--;
                    cnt[i]--;
                }
            }
            return;
        }
    }
};

