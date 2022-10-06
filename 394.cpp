class Solution {
public:
    string decodeString(string s) {
        s_ = s;
        return decode();
    }
private:
    int right_;
    string s_;
    string decode() {
        string result{};
        while (right_ < s_.length()) {
            if (s_[right_] == ']') {
                return result;
            }
            if (isdigit(s_[right_])) {
                int n = parseInt();
                right_++;
                string deeper = decode();
                while (n--) {
                    result += deeper;
                }
            } else {
                result += s_[right_];
            }
            right_++;
        }
        return result;
    }
    int parseInt() {
        int result = 0;
        while (isdigit(s_[right_])) {
            result = 10 * result + s_[right_] - '0';
            right_++;
        }
        return result;
    }
};