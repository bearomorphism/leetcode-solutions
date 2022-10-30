class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us1(nums1.begin(), nums1.end()), us2(nums2.begin(), nums2.end());
        unordered_set<int> intersect;
        for (int i: us1) {
            auto it = us2.find(i);
            if (it != us2.end()) intersect.insert(i);
        }
        vector<int> a, b;
        for (int i: us1) {
            if (intersect.find(i) == intersect.end()) a.push_back(i);
        }
        for (int i: us2) {
            if (intersect.find(i) == intersect.end()) b.push_back(i);
        }
        return {a, b};
    }
};