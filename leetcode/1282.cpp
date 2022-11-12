class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result, groups(501);
        int n = groupSizes.size();
        for (int i = 0; i < n; i++) {
            int s = groupSizes[i];
            groups[s].push_back(i);
            if (groups[s].size() == s) {
                result.push_back(groups[s]);
                groups[s].clear();
            }
        }
        return result;
    }
};