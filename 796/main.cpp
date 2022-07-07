class Solution {
public:
    bool rotateString(string s, string goal) {
        string ss;
        ss += s;
        ss += s;
        return s.length() == goal.length() && ss.find(goal) != string::npos;
    }
};