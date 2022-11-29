class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (um.find(val) == um.end()) {
            um[val] = v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (um.find(val) == um.end()) {
            return false;
        }
        um[v.back()] = um[val];
        v[um[val]] = v.back();
        v.pop_back();
        um.erase(val);
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
private:
    unordered_map<int, int> um;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */