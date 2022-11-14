class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        string ret = "";
        do {
            if ((arr[0] == 2 && arr[1] <= 3 || arr[0] <= 1) && arr[2] <= 5) {
                string news = "  :  ";
                news[0] = arr[0] + '0';
                news[1] = arr[1] + '0';
                news[3] = arr[2] + '0';
                news[4] = arr[3] + '0';
                ret = max(ret, news);
            }
        } while (next_permutation(arr.begin(), arr.end()));
        return ret;
    }
};