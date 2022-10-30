class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> v, v2;
        int n = dominoes.length();
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                v.push_back(i);
            }
        }

        while (!v.empty()) {
            v2.clear();
            vector<int> updateL, updateR;
            for (int i: v) {
                if (dominoes[i] == 'L' && i > 0 && dominoes[i - 1] == '.') {
                    updateL.push_back(i - 1);
                } else if (dominoes[i] == 'R' && i < n - 1 && dominoes[i + 1] == '.') {
                    updateR.push_back(i + 1);
                }
            }
            for (int i: updateL) {
                dominoes[i] = 'L';
                v2.push_back(i);
            }
            for (int i: updateR) {
                if (dominoes[i] == 'L') dominoes[i] = '.';
                else {
                    dominoes[i] = 'R';
                    v2.push_back(i);
                }
            }
            v = v2;
        }
        return dominoes;
    }
};