class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char result = 'z' + 1;
        for (char c: letters) {
            if (c > target) {
                result = min(result, c);
            }
        }
        return result == 'z' + 1 ? letters[0] : result;
    }
};