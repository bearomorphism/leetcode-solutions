class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int cnt = 0;
        unordered_map<long long, int> s1, s2;
        for (int i: nums1) s1[(long long)i * i]++;
        for (int i: nums2) s2[(long long)i * i]++;
        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < i; j++)
                if (auto it = s2.find((long long)nums1[i] * nums1[j]); it != s2.end()) cnt += it->second;

        for (int i = 0; i < nums2.size(); i++)
            for (int j = 0; j < i; j++)
                if (auto it = s1.find((long long)nums2[i] * nums2[j]); it != s1.end()) cnt += it->second;
        return cnt;
    }
};