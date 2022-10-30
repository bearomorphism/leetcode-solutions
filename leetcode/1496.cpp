class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int, int>> us;
        us.insert({x, y});
        for (char c: path) {
            if (c == 'N') x++;
            else if (c == 'S') x--;
            else if (c == 'W') y++;
            else y--;
            if (us.count({x, y})) return true;
            us.insert({x, y});
        }
        return false;
    }
};