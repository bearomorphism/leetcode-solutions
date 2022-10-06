class TimeMap {
public:
    TimeMap() {
        table_ = {};
    }

    void set(string key, string value, int timestamp) {
        table_[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = table_.find(key);
        if (it == table_.end()) {
            return "";
        }
        auto &arr = it->second;
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid].first > timestamp) r = mid;
            else l = mid + 1;
        }
        if (r == 0) return "";
        return arr[r - 1].second;
    }
private:
    unordered_map<string, vector<pair<int, string>>> table_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */