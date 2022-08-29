class Solution {
private:
    void update(vector<int>& cells) {
        vector<int> v(8, 0);
        v[0] = v[7] = 0;
        for (int i = 1; i < 7; i++) {
            v[i] = cells[i - 1] == cells[i + 1];
        }
        cells = v;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        n--;
        update(cells);
        vector<int> u(64, -1);
        int x = 0;
        int cycle = -1;
        while (n) {
            n--;
            x++;
            update(cells);
            if (cycle == -1){
                int t = 0;
                for (int i = 0; i < 6; i++) {
                    t = t | (cells[i + 1] << i);
                }
                if (u[t] == -1)
                    u[t] = x;
                else {
                    cycle = x - u[t];
                    n %= cycle;
                }
            }
        }
        return cells;
    }
};