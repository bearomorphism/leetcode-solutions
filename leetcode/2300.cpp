class Solution {
public:
    vector<int> successfulPairs(vector<int>& potions, vector<int>& spells, long long success) {
        sort(spells.begin(), spells.end());
        vector<int> ret;
        for (int p: potions) {
            double d = (double)success / p;
            auto it = lower_bound(spells.begin(), spells.end(), d);
            ret.push_back(spells.size() - (it - spells.begin()));
        }
        return ret;
    }
};