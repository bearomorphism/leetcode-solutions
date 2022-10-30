class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        vector<int> cnt1(10), cnt2(10);
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) a++;
            else {
                cnt1[guess[i] - '0']++;
                cnt2[secret[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            b += min(cnt1[i], cnt2[i]);
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};