class Solution {
private:
    int nBytes(int n) {
        if ((n >> 7) & 1) {
            if ((n >> 6) & 1) {
                if ((n >> 5) & 1) {
                    if ((n >> 4) & 1) {
                        if ((n >> 3) & 1) return -1;
                        return 3;
                    }
                    return 2;
                }
                return 1;
            }
            return -1;
        }
        return 0;
    }
    bool isValidByte(int n) {
        return ((n >> 7) & 1) && !((n >> 6) & 1);
    }
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, n = data.size();
        while (i < n) {
            int step = nBytes(data[i]);
            if (step == -1) return false;
            i++;
            while (step) {
                step--;
                if (i == n || !isValidByte(data[i])) {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};