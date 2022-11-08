class Solution {
public:
    string makeGood(string s) {
        string result = "";
        for (char c: s) {
            if (!result.empty() && (islower(result.back()) && toupper(result.back()) == c || isupper(result.back()) && tolower(result.back()) == c)) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
