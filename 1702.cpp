class Solution {
public:
    string maximumBinaryString(string binary) {
        int i = 0, len = binary.length();
        while (i < len && binary[i] == '1') i++;
        if (i == len) return binary;
        int cnt = 0;
        for (int j = i; j < len; j++) {
            cnt += binary[j] - '0';
        }
        int k = len - 1;
        while (cnt--) binary[k--] = '1';
        binary[k--] = '0';
        while (k >= 0) binary[k--] = '1';
        return binary;
    }
};