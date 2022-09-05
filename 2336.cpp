class SmallestInfiniteSet {
private:
    set<int> s;
public:
    SmallestInfiniteSet() {
        s.clear();
        s.insert(1);
    }

    int popSmallest() {
        auto it = s.begin();
        int ret = *it;
        s.erase(it);
        if (s.size() == 0) s.insert(ret + 1);
        return ret;
    }

    void addBack(int num) {
        if (s.find(num) == s.end() && num < *prev(s.end())) s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */