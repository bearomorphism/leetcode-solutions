class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<long long> v;
        for (string &s: ops) {
            if (s == "C") v.pop_back();
            else if (s == "D") v.push_back(v.back() * 2);
            else if (s == "+") v.push_back(v[v.size() - 2] + v[v.size() - 1]);
            else v.push_back(stoi(s));
        }
        long long ans = 0;
        for (long long i: v) {
            ans += i;
        }
        return ans;
    }
};