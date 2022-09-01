class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < deck.size(); i++) {
            q.push(i);
        }
        vector<int> ret(deck.size());
        for (int d: deck) {
            ret[q.front()] = d;
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ret;
    }
};