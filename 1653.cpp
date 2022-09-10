class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> del_left(n), del_right(n);
        if (s[0] == 'b') del_left[0] = 1;
        for (int i = 1; i < n; i++) {
            del_left[i] = del_left[i - 1] + (s[i] == 'b' ? 1 : 0);
        }
        if (s[n - 1] == 'a') del_right[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            del_right[j] = del_right[j + 1] + (s[j] == 'a' ? 1 : 0);
        }

        int result = min(del_left[n - 1], del_right[0]);
        for (int i = 0; i < n - 1; i++) {
            result = min(result, del_left[i] + del_right[i + 1]);
        }
        return result;
    }
};