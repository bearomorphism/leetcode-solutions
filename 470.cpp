// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (1) {
            int t = rand7() - 1 + 7 * (rand7() - 1);
            if (t < 40) {
                return (t % 10) + 1;
            }
        }
    }
};