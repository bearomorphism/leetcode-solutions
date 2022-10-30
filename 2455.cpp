class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, cnt = 0;
        for (int i: nums) {
            if (i % 6 == 0) {

            sum += i;
            cnt ++;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
};