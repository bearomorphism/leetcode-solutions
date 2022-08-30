class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ret = 0;
        for (string& s: logs) {
            if (s == "../") ret = max(0, ret - 1);
            else if (s != "./") ret++;
        }
        return ret;
    }
};