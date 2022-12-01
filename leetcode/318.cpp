class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0, n = words.size();
        vector<int> v;
        for (auto &w: words) {
            v.emplace_back(helper(w));
        }

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (!(v[i] & v[j]))
                    result = max<int>(result, words[i].length() * words[j].length());
        return result;
    }
private:
    int helper(const string &s) {
        int result = 0;
        for (char c: s)
            result |= 1 << (c - 'a');
        return result;
    }
};