class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, answ = 1;
        for (int i = 1; i < nums1.size(); i++) {
            if (nums1[i - 1] >= nums2[i] || nums2[i - 1] >= nums1[i]) {
                answ++;
            } else if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i]) {
                int tmp = answ;
                answ = ans + 1;
                ans = tmp;
            } else {
                ans = min(ans, answ);
                answ = ans + 1;
            }
        }
        return min(ans, answ);
    }
};