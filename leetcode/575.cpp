class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> t;
        for (int i: candyType) {
            t.insert(i);
        }
        return min(candyType.size() / 2, t.size());
    }
};