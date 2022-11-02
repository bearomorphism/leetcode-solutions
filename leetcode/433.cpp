class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        
        bank.push_back(start);
        int n = bank.size();
        vector<bool>vis(n);
        vector<int> v, v2;
        v.push_back(n - 1);
        
        int round{ 0 };
        while (!v.empty()) {
            round++;
            for (int i: v) {
                for (int j = 0; j < n; j++) {
                    if (!vis[j] && helper(bank[i], bank[j])) {
                        if (bank[j] == end) return round;
                        vis[j] = true;
                        v2.push_back(j);
                    }
                }
            }
            v = v2;
            v2.clear();
        }
        return -1;
    }
private:
    bool helper(const string &a, const string &b) {
        int cnt{ 0 };
        for (int i{ 0 }; i < a.length(); i++) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }
};
