class Solution {
public:
    vector<int> constructRectangle(int area) {
        int height = 1;
        for (int i = 2; i * i <= area; i++) {
            if (area % i == 0) height = i;
        }
        return {area / height, height};
    }
};