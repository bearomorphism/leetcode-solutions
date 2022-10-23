class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> v1, v2;
        for (char c: num1) v1.push_back(c - '0');
        for (char c: num2) v2.push_back(c - '0');
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());

        vector<int> result(500);
        for (int i = 0; i < v1.size(); i++) {
            vector<int> s;
            int incr = 0;
            for (int j = 0; j < v2.size(); j++) {
                int prod = v2[j] * v1[i] + incr;
                s.push_back(prod % 10);
                incr = prod / 10;
            }
            if (incr) {
                s.push_back(incr);
            }

            incr = 0;
            for (int k = 0; k < s.size(); k++) {
                int summation = s[k] + result[i + k] + incr;
                result[i + k] = summation % 10;
                incr = summation / 10;
            }

            int u = i + s.size();
            while (incr) {
                int summation = result[u] + incr;
                result[u] = summation % 10;
                incr = summation / 10;
                u++;
            }
        }

        int x = 499;
        while (x >= 0 && !result[x]) x--;
        if (x < 0) return "0";

        string ret;
        while (x >= 0) {
            ret.push_back(result[x] + '0');
            x--;
        }
        return ret;
    }
};